//  Autor : Naim Diestra
//  Fecha : 13/10/2026

#include <iostream>
#include <vector>
using namespace std;

#define N 4 // representa la cantidad de movimientos disponibles
const int dFila[] = {-1, 0, 1, 0};
const int dCol[] = {0, 1, 0, -1};

void imprimir(const vector<vector<int>>& laberinto) {
    for (int i = 0; i < laberinto.size(); i++) {
        for (int j = 0; j < laberinto[0].size(); j++) {
            cout << laberinto[i][j] << " ";
        }
        cout << endl;
    }
}

bool recorrerLaberinto(vector<vector<int>>& laberinto, int fila, int col, int finFila, int finCol) {
    // Caso base: la casilla se excedió de los límites
    if (fila < 0 || fila >= finFila || col < 0 || col >= finCol)
        return false;

    // Caso base: me encuentro en una casilla inválida
    if (laberinto[fila][col] != 1)
        return false;

    // Hacer: marcamos el estado 2 (recorrido) en el laberinto
    laberinto[fila][col] = 2;

    // Caso base: se llegó al final
    if (fila == finFila - 1 && col == finCol - 1) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (recorrerLaberinto(laberinto, fila + dFila[i], col + dCol[i], finFila, finCol))
            return true;
    }

    // Deshacer: marcamos el estado 1 (no recorrido) en el laberinto
    laberinto[fila][col] = 1;

    return false;
}

int main() {
    vector<vector<int>> laberinto = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    cout << "Laberinto: " << endl;
    imprimir(laberinto);

    if (recorrerLaberinto(laberinto, 0, 0,
                          laberinto.size(), laberinto[0].size())) {
        cout << "\nExito: se llego al final\n";
        imprimir(laberinto);
    }

    return 0;
}
