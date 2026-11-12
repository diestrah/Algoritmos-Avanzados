#include <iostream>
#include <vector>
#include <algorithm>    // min(), max()
#include <climits>      // INT_MIN, INT_MAX
#include <cstdlib>      // srand(), rand()
#include <ctime>        // time()
using namespace std;

#define ITERACIONES 1000
#define MAQUINAS 3
#define ALFA 0.3

struct Tarea{
    char nombre;
    int tiempo;
};

struct Maquina{
    vector<char> tareas;
    int cargaTotal;
};

struct Asignacion{
    vector<Maquina> maquinas;
    int tiempoMaximo;
};

bool mayorTiempo(const Tarea& a, const Tarea& b) {
    return a.tiempo > b.tiempo;
}

int contarCandidatosRCL(const vector<Tarea>& pendientes, double umbral) {
    int cantidadRCL = 0;
    while (cantidadRCL < pendientes.size() &&
        pendientes[cantidadRCL].tiempo >= umbral) {
        cantidadRCL++;
    }
    return cantidadRCL;
}

Asignacion asignarTareas(const vector<Tarea>& tareas) {
    vector<Maquina> maquinas(MAQUINAS, {{}, 0});
    // Las tareas ya se encuentran ordenadas descendentemente por duración
    vector<Tarea> pendientes = tareas;

    while (!pendientes.empty()) {
        int beta = pendientes.front().tiempo; // Contiene el máximo tiempo
        int tau = pendientes.back().tiempo; // Contiene el mínimo tiempo
        double umbral = beta - ALFA * (beta - tau);

        // La RCL ocupa las primeras posiciones del vector
        int cantidadRCL = contarCandidatosRCL(pendientes, umbral);
        int posicion = rand() % cantidadRCL;
        Tarea tareaElegida = pendientes[posicion];
        pendientes.erase(pendientes.begin() + posicion);

        // Se le asignará la tarea a la máquina con menor carga
        int indiceMaquina = 0, menorCarga = INT_MAX;
        for (int i = 0; i < MAQUINAS; i++) {
            if (menorCarga > maquinas[i].cargaTotal) {
                menorCarga = maquinas[i].cargaTotal;
                indiceMaquina = i;
            }
        }

        maquinas[indiceMaquina].tareas.push_back(tareaElegida.nombre);
        maquinas[indiceMaquina].cargaTotal += tareaElegida.tiempo;
    }

    // El tiempo de finalización corresponde a la mayor carga
    int tiempoMaximo = INT_MIN;
    for (int i = 0; i < MAQUINAS; i++) {
        tiempoMaximo = max(tiempoMaximo, maquinas[i].cargaTotal);
    }

    return {maquinas, tiempoMaximo};
}

Asignacion buscarMejorAsignacion(const vector<Tarea>& tareas) {
    Asignacion mejor{{}, INT_MAX};

    for (int i = 0; i < ITERACIONES; i++) {
        Asignacion asignacion = asignarTareas(tareas);
        if (asignacion.tiempoMaximo < mejor.tiempoMaximo) {
            mejor = asignacion;
        }
    }

    return mejor;
}

void imprimir(const Asignacion& asignacion) {
    cout << "Cantidad de maquinas: " << MAQUINAS << endl;
    cout << "Alfa: " << ALFA << endl;
    cout << "Iteraciones: " << ITERACIONES << endl;

    int i = 1;
    for (const Maquina& maquina : asignacion.maquinas) {
        cout << "\nMaquina " << i << ":" << endl;
        cout << "Tareas asignadas: [";
        for (int k = 0; k < maquina.tareas.size(); k++) {
            if (k != 0) cout << ", ";
            cout << maquina.tareas[k];
        }
        cout << "]\nCarga total: " << maquina.cargaTotal << endl;
        i++;
    }

    cout << "\nTiempo para completar todas las tareas: " << asignacion.tiempoMaximo << endl;
}

int main() {
    vector<Tarea> tareas{
        {'A', 2},
        {'B', 8},
        {'C', 6},
        {'D', 5},
        {'E', 10},
        {'F', 3},
        {'G', 8},
        {'H', 4},
        {'I', 7},
    };

    srand(time(nullptr));
    sort(tareas.begin(), tareas.end(), mayorTiempo);

    Asignacion asignacion = buscarMejorAsignacion(tareas);
    imprimir(asignacion);

    return 0;
}
