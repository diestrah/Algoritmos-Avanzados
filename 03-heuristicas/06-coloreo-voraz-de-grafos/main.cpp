#include <iostream>
#include <algorithm>
using namespace std;

#define N 8

struct Vertice {
    int indice;
    int grado;
};

bool compararVertices(const Vertice& a, const Vertice& b) {
    if (a.grado != b.grado) {
        return a.grado > b.grado;
    }
    return a.indice < b.indice;
}

void prepararOrden(const int matriz[N][N], Vertice* orden) {
    for (int i = 0; i < N; i++) {
        orden[i].indice = i;
        orden[i].grado = 0;

        for (int j = 0; j < N; j++) {
            orden[i].grado += matriz[i][j];
        }
    }
    sort(orden, orden + N, compararVertices);
}

void colorearGrafo(int matriz[N][N], const Vertice* orden, int* colores) {
    for (int i = 0; i < N; i++) {
        int vertice = orden[i].indice;
        bool usados[N + 1] = {};

        // Registrar los colores de los vecinos ya coloreados
        for (int vecino = 0; vecino < N; vecino++) {
            if (matriz[vertice][vecino] == 1 &&
                colores[vecino] != 0) {
                usados[colores[vecino]] = true;
            }
        }
        // Elegir el menor color disponible
        int color = 1;
        while (usados[color]) {
            color++;
        }
        colores[vertice] = color;
    }
}

void imprimir(const int* colores) {
    cout << "Vertice: ";
    for (int i = 0; i < N; i++)
        cout << (char)('A' + i) << " ";

    cout << "\nColor:   ";
    int cantidadColores = 0;
    for (int i = 0; i < N; i++) {
        cout << colores[i] << " ";
        cantidadColores = max(cantidadColores, colores[i]);
    }

    cout << "\nCantidad de colores utilizados: "
         << cantidadColores << "\n";
}

int main() {
    int matriz[N][N] = {
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0}
    };

    Vertice orden[N];
    int colores[N] = {}; // inicializamos en 0 todos los colores asignados

    prepararOrden(matriz, orden);
    colorearGrafo(matriz, orden, colores);
    imprimir(colores);

    return 0;
}