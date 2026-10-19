/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 25/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <vector>

using namespace std;

void imprimir(const vector<int>& vector) {
    cout << "[";
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i];
        if (i < vector.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

// La variable ini indica el elemento inicial del arreglo
void generarCombinaciones(int n, int k, int inicio, vector<int>& combinacion) {
    // Caso base: Si tengo k elementos, se construyó una combinación completa
    if (combinacion.size() == k) {
        imprimir(combinacion);
        return;
    }

    for (int i = inicio; i <= n; i++) {
        // Hacer
        combinacion.push_back(i);
        // Explorar: comenzamos desde i + 1 para evitar repetir elementos
        // y así no generar la misma combinación en distinto orden
        generarCombinaciones(n, k, i + 1, combinacion);
        // Deshacer
        combinacion.pop_back();
    }
}

int main() {
    int n = 4; // rango de elementos: [1, n]
    int k = 2; // cantidad de elementos
    vector<int> combinacion;

    generarCombinaciones(n, k, 1, combinacion);

    return 0;
}
