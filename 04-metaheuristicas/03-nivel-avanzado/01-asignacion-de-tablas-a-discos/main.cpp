#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdlib>
using namespace std;

#define ALFA 0.5
#define ITERACIONES 1000

struct Tabla{
    int espacioRequerido;
    int iopsRequeridos;
    double iopsPorGB;
};

struct Disco{
    int espacioDisponible;
    int iopsDisponibles;
    vector<int> tablasAsignadas;
};

struct Asignacion{
    vector<Disco> discos;
    int minimoIopsRestantes;
};

vector<int> generarRCLDiscos(const vector<Disco>& discos,
                             const Tabla& tabla) {
    int minimo = INT_MAX;
    int maximo = INT_MIN;

    for (int i = 0; i < discos.size(); i++) {
        if (discos[i].espacioDisponible >= tabla.espacioRequerido &&
            discos[i].iopsDisponibles >= tabla.iopsRequeridos) {
            minimo = min(minimo, discos[i].iopsDisponibles);
            maximo = max(maximo, discos[i].iopsDisponibles);
        }
    }

    // Si no existen candidatos para la RCL, retornamos nulo
    if (minimo == INT_MAX) return {};

    double umbral = maximo - ALFA * (maximo - minimo);
    vector<int> rcl;

    for (int i = 0; i < discos.size(); i++) {
        if (discos[i].espacioDisponible >= tabla.espacioRequerido &&
            discos[i].iopsDisponibles >= tabla.iopsRequeridos &&
            discos[i].iopsDisponibles >= umbral) {
            // La RCL almacenará los índices de los discos candidatos
            rcl.push_back(i);
        }
    }
    return rcl;
}

bool existeDiscoFactible(const Tabla& tabla, const vector<Disco>& discos) {
    for (const Disco& disco : discos) {
        if (disco.espacioDisponible >= tabla.espacioRequerido &&
            disco.iopsDisponibles >= tabla.iopsRequeridos) {
            return true;
        }
    }
    return false;
}

vector<int> generarRCLTablas(const vector<Tabla>& tablas,
                             const vector<bool>& tablasAsignadas,
                             const vector<Disco>& discos) {
    double minimo = INT_MAX;
    double maximo = INT_MIN;

    for (int i = 0; i < tablas.size(); i++) {
        if (!tablasAsignadas[i] && existeDiscoFactible(tablas[i], discos)) {
            minimo = min(minimo, tablas[i].iopsPorGB);
            maximo = max(maximo, tablas[i].iopsPorGB);
        }
    }

    if (minimo == INT_MAX) return {};

    double umbral = maximo - ALFA * (maximo - minimo);
    vector<int> rcl;

    for (int i = 0; i < tablas.size(); i++) {
        if (tablas[i].iopsPorGB >= umbral &&
            !tablasAsignadas[i] && existeDiscoFactible(tablas[i], discos)) {
            // La RCL almacenara los indices de las tablas candidatas
            rcl.push_back(i);
        }
    }

    return rcl;
}

Asignacion construirAsignacion(const vector<Tabla>& tablas,
                               const vector<Disco>& discosIniciales) {
    vector<bool> tablasAsignadas(tablas.size(), false);
    Asignacion asignacion{discosIniciales, INT_MAX};
    Asignacion asignacionIncompleta{{}, INT_MIN};

    for (int i = 0; i < tablas.size(); i++) {
        vector<int> rclTabla = generarRCLTablas(tablas, tablasAsignadas, asignacion.discos);
        // No se puede completar esta construccion
        if (rclTabla.empty()) return asignacionIncompleta;

        int posTabla = rand() % rclTabla.size();
        int indiceTabla = rclTabla[posTabla];
        const Tabla& tablaElegida = tablas[indiceTabla];

        vector<int> rclDiscos = generarRCLDiscos(asignacion.discos, tablaElegida);
        // No se puede completar esta construccion
        if (rclDiscos.empty()) return asignacionIncompleta;

        int posDiscos = rand() % rclDiscos.size();
        int indiceDiscos = rclDiscos[posDiscos];
        // Actualizamos directamente el disco seleccionado
        Disco& discoElegido = asignacion.discos[indiceDiscos];

        discoElegido.espacioDisponible -= tablaElegida.espacioRequerido;
        discoElegido.iopsDisponibles -= tablaElegida.iopsRequeridos;
        discoElegido.tablasAsignadas.push_back(indiceTabla + 1);

        tablasAsignadas[indiceTabla] = true;
    }

    for (const Disco& disco : asignacion.discos) {
        asignacion.minimoIopsRestantes =
            min(disco.iopsDisponibles, asignacion.minimoIopsRestantes);
    }

    return asignacion;
}


Asignacion buscarMejorAsignacion(const vector<Tabla>& tablas,
                                 const vector<Disco>& discosIniciales) {
    Asignacion mejorAsignacion{{}, INT_MIN};

    for (int i = 0; i < ITERACIONES; i++) {
        Asignacion asignacion = construirAsignacion(tablas, discosIniciales);
        // Entre las asignaciones completas, conservamos aquellas cuyo disco con menos
        // IOPS disponibles sea el mayor porque implica una mejor distribucion de carga
        if (!asignacion.discos.empty() &&
            mejorAsignacion.minimoIopsRestantes < asignacion.minimoIopsRestantes) {
            mejorAsignacion = asignacion;
        }
    }
    return mejorAsignacion;
}

void imprimir(const Asignacion& asignacion) {
    cout << "Alfa: " << ALFA << endl;
    cout << "Iteraciones: " << ITERACIONES << endl;

    for (int i = 0; i < asignacion.discos.size(); i++) {
        cout << "\nDisco " << i + 1 << ":" << endl;
        cout << "Tablas asignadas: [";
        for (int j = 0; j < asignacion.discos[i].tablasAsignadas.size(); j++) {
            if (j != 0) cout << ", ";
            cout << asignacion.discos[i].tablasAsignadas[j];
        }
        cout << "]\nEspacio disponible: " << asignacion.discos[i].espacioDisponible << " GB" << endl;
        cout << "IOPS restantes: " << asignacion.discos[i].iopsDisponibles << endl;
    }
    cout << "\nMenor cantidad de IOPS restantes: " << asignacion.minimoIopsRestantes << endl;
}

void calcularIopsPorGB(vector<Tabla>& tabla) {
    for (int i = 0; i < tabla.size(); i++) {
        tabla[i].iopsPorGB =
            (double)tabla[i].iopsRequeridos / tabla[i].espacioRequerido;
    }
}

int main() {
    vector<Tabla> tablas = {
        {20, 150},
        {10, 100},
        {15, 80},
        {100, 50},
        {50, 120},
        {100, 10}
    };

    vector<Disco> discosIniciales = {
        {800, 250},
        {750, 200},
        {850, 200}
    };

    calcularIopsPorGB(tablas);
    srand(time(nullptr));

    Asignacion asignacion = buscarMejorAsignacion(tablas, discosIniciales);
    if (asignacion.discos.empty()) {
        cout << "No se encontró una asignación completa" << endl;
    }
    else {
        imprimir(asignacion);
    }

    return 0;
}
