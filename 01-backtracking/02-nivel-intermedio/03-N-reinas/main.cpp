#include <iostream>
#include <vector>
using namespace std;

#define N 6

void imprimir(const vector<vector<int>>& tablero) {
    for (int i = 0; i < tablero.size(); i++) {
        for (int j = 0; j < tablero[i].size(); j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}

bool esCasillaValida(const vector<vector<int>>& tablero, int fila, int col) {
    // Verificamos la columna superior
    for (int i = fila - 1; i >= 0; i--) {
        if (tablero[i][col] != 0) {
            return false;
        }
    }

    // Verificamos la diagonal superior izquierda
    for (int i = fila - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (tablero[i][j] != 0) {
            return false;
        }
    }

    // Verificamos la diagonal superior derecha
    for (int i = fila - 1, j = col + 1; i >= 0 && j < tablero.size(); i--, j++) {
        if (tablero[i][j] != 0) {
            return false;
        }
    }

    // Si superó todas las validaciones, se puede insertar la reina
    return true;
}

bool resolverNReinas(vector<vector<int>>& tablero, int fila) {
    // Caso base
    if (fila == N) return true;

    for (int col = 0; col < N; col++) {
        if (esCasillaValida(tablero, fila, col)) {
            // Hacer: colocamos la reina (1) en el tablero
            tablero[fila][col] = 1;

            if (resolverNReinas(tablero, fila + 1))
                return true;

            // Deshacer: sacamos la reina (0) del tablero
            tablero[fila][col] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> tablero(N, vector<int>(N, 0));

    if (resolverNReinas(tablero, 0)) {
        cout << "Exito: se pudo resolver el problema de las N reinas" << endl;
        imprimir(tablero);
    }
    else {
        cout << "No se pudo resolver el problema de las N reinas" << endl;
    }

    return 0;
}
