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

vector<int> construirRCL(const vector<Tarea>& tareas,
                         const vector<bool>& asignadas) {
    int tau = INT_MAX;  // Contiene la minima duracion
    int beta = INT_MIN; // Contiene el maxima duracion
    for (int i = 0; i < tareas.size(); i++) {
        if (!asignadas[i]) {
            tau = min(tau, tareas[i].tiempo);
            beta = max(beta, tareas[i].tiempo);
        }
    }

    if (beta == INT_MIN) return {};

    // Preferiremos las tareas de mayor duración
    double umbral = beta - ALFA * (beta - tau);
    vector<int> rcl; // Almacenará los índices de las tareas candidatas

    for (int i = 0; i < tareas.size(); i++) {
        if (!asignadas[i] &&
            tareas[i].tiempo >= umbral) {
            rcl.push_back(i);
        }
    }
    return rcl;
}

Asignacion asignarTareas(const vector<Tarea>& tareas) {
    vector<Maquina> maquinas(MAQUINAS, {{}, 0});
    vector<bool> asignadas(tareas.size(), false);

    while (true) {
        vector<int> rcl = construirRCL(tareas, asignadas);
        if (rcl.empty()) break;

        int posicion = rand() % rcl.size(); // Almacena la posición del RCL a usar
        int indiceTarea = rcl[posicion]; // Almacena el índice de la tarea a usar
        char nombreTarea = tareas[indiceTarea].nombre;

        // Se le asignará la tarea a la máquina con menor carga
        int indiceMaquina = 0, menorCarga = INT_MAX;
        for (int i = 0; i < MAQUINAS; i++) {
            if (menorCarga > maquinas[i].cargaTotal) {
                menorCarga = maquinas[i].cargaTotal;
                indiceMaquina = i;
            }
        }

        maquinas[indiceMaquina].tareas.push_back(nombreTarea);
        maquinas[indiceMaquina].cargaTotal += tareas[indiceTarea].tiempo;
        asignadas[indiceTarea] = true;
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

    Asignacion asignacion = buscarMejorAsignacion(tareas);
    imprimir(asignacion);

    return 0;
}
