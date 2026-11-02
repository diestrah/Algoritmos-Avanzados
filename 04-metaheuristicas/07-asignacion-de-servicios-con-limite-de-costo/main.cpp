#include <iostream>
#include <vector>
#include <algorithm>    // min(), max()
#include <climits>      // INT_MIN, INT_MAX
#include <ctime>        // time()
#include <cstdlib>      // srand(), rand()
using namespace std;

#define ITERACIONES 1000
#define LIMITE 20
#define ALFA 0.3

struct Envio{
    char ciudad;
    int numeroMotorizado;
    int costoEnvio;
};

struct Asignacion{
    vector<Envio> envios;
    int costoTotal;
};

vector<int> generarRCL(const vector<vector<int>>& matrizTarifas,
                       const vector<bool>& motorizadosAsignados,
                       int costoTransporte,
                       int indiceCiudad) {
    int minimo = INT_MAX;
    int maximo = INT_MIN;

    // Evaluar los motorizados disponibles que cumplen el límite
    for (int i = 0; i < matrizTarifas.size(); i++) {
        int tarifa = matrizTarifas[i][indiceCiudad];

        if (!motorizadosAsignados[i] &&
            tarifa + costoTransporte <= LIMITE) {
            minimo = min(minimo, tarifa);
            maximo = max(maximo, tarifa);
        }
    }

    // No hay motorizados disponibles para esta ciudad
    if (maximo == INT_MIN) return {};

    // Definimos la tarifa máxima aceptada para ingresar a la RCL
    double umbral = minimo + ALFA * (maximo - minimo);
    vector<int> rcl;

    for (int i = 0; i < matrizTarifas.size(); i++) {
        int tarifa = matrizTarifas[i][indiceCiudad];
        if (!motorizadosAsignados[i] &&
            tarifa + costoTransporte <= LIMITE &&
            tarifa <= umbral) {
            rcl.push_back(i);
        }
    }

    return rcl;
}

Asignacion construirAsignacion(const vector<vector<int>>& matrizTarifas,
                               const vector<int>& costosTransporte) {

    vector<bool> motorizadosAsignados(matrizTarifas.size(), false);
    Asignacion asignacion{{}, 0};

    // Atender las ciudades en el orden en que se reciben
    for (int indiceCiudad = 0; indiceCiudad < costosTransporte.size(); indiceCiudad++) {
        vector<int> rcl = generarRCL(matrizTarifas, motorizadosAsignados,
                                     costosTransporte[indiceCiudad], indiceCiudad);

        // Devolvemos la asignación parcial si no se puede continuar
        if (rcl.empty()) return asignacion;

        // La posición pertenece a la RCL; el índice, a la matriz.
        int posicion = rand() % rcl.size();
        int indiceMotorizado = rcl[posicion];

        // Construimos el envío
        Envio envio;
        envio.ciudad = 'A' + indiceCiudad;
        envio.numeroMotorizado = indiceMotorizado + 1;
        envio.costoEnvio = costosTransporte[indiceCiudad] + matrizTarifas[indiceMotorizado][indiceCiudad];

        // Lo agregamos a la asignación
        asignacion.envios.push_back(envio);
        asignacion.costoTotal += envio.costoEnvio;

        motorizadosAsignados[indiceMotorizado] = true;
    }

    return asignacion;
}

Asignacion buscarMejorAsignacion(const vector<vector<int>>& matrizTarifas,
                                 const vector<int>& costosTransporte) {

    Asignacion mejorAsignacion{{}, INT_MAX};

    for (int iteracion = 0; iteracion < ITERACIONES; iteracion++) {
        Asignacion asignacion = construirAsignacion(matrizTarifas, costosTransporte);
        bool esCompleta = asignacion.envios.size() == costosTransporte.size();

        // Solo compararemos las asignaciones completas
        if (esCompleta &&
            asignacion.costoTotal < mejorAsignacion.costoTotal) {
            mejorAsignacion = asignacion;
        }
    }

    return mejorAsignacion;
}

void imprimir(const Asignacion& asignacion) {
    cout << "Limite por envio: " << LIMITE << " soles\n";
    cout << "Alfa: " << ALFA << "\n";
    cout << "Iteraciones: " << ITERACIONES << "\n";

    for (const Envio& envio : asignacion.envios) {
        cout << "\nCiudad " << envio.ciudad << ":\n";
        cout << "Motorizado: " << envio.numeroMotorizado << "\n";
        cout << "Costo del envio: " << envio.costoEnvio << " soles\n";
    }

    cout << "\nCosto total: " << asignacion.costoTotal << " soles\n";
}

int main() {
    // Filas: motorizados. Columnas: ciudades.
    const vector<vector<int>> matrizTarifas = {
        {3, 4, 5, 6},
        {5, 2, 3, 4},
        {7, 5, 4, 2},
        {8, 7, 5, 1},
        {4, 3, 7, 5}
    };

    const vector<int> costosTransporte = {16, 15, 12, 18};

    srand(time(nullptr));

    Asignacion mejorAsignacion = buscarMejorAsignacion(matrizTarifas, costosTransporte);

    if (mejorAsignacion.envios.size() == costosTransporte.size()) {
        imprimir(mejorAsignacion);
    }
    else {
        cout << "No se encontro una asignacion completa.\n";
    }

    return 0;
}
