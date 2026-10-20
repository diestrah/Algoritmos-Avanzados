#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define N 9 // numero de tareas a asignar
#define M 3 // numero de maquinas

struct Tarea{
    char nombre;
    int tiempo;
};

bool comparar(const Tarea& a, const Tarea& b) {
    if (a.tiempo != b.tiempo)
        return a.tiempo > b.tiempo;
    return a.nombre < b.nombre;
}

void asignarTareas(const Tarea* tareas, vector<vector<Tarea>>& maquinas, int* tiempos) {
    for (int i = 0; i < N; i++) {
        int menorCarga = INT_MAX, maquinaElegida = -1;

        for (int j = 0; j < M; j++) {
            if (menorCarga > tiempos[j]) {
                menorCarga = tiempos[j];
                maquinaElegida = j;
            }
        }

        maquinas[maquinaElegida].push_back(tareas[i]);
        tiempos[maquinaElegida] += tareas[i].tiempo;
    }
}

int maximo(const int* arr) {
    int max_val = INT_MIN;
    for (int i = 0; i < M; i++) {
        max_val = max(arr[i], max_val);
    }
    return max_val;
}

void imprimir(const vector<vector<Tarea>>& maquinas, const int* tiempos) {
    for (int i = 0; i < M; i++) {
        cout << "Maquina " << i + 1 << ':' << endl;
        cout << "Tareas asignadas: [";
        for (int j = 0; j < maquinas[i].size(); j++) {
            if (j > 0) cout << ", ";
            cout << maquinas.at(i).at(j).nombre;
        }
        cout << "]\nCarga total: " << tiempos[i] << endl << endl;
    }
    cout << "Tiempo para completar todas las tareas: " << maximo(tiempos) << endl;
}

int main() {
    vector<vector<Tarea>> maquinas(M);
    int tiempos[M] = {};
    Tarea tareas[N]{
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

    sort(tareas, tareas + N, comparar); // ordenamos las tareas por mayor tiempo
    asignarTareas(tareas, maquinas, tiempos);
    imprimir(maquinas, tiempos);

    return 0;
}
