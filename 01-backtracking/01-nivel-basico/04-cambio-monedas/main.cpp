/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 26/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <vector>

using namespace std;

void imprimir(const vector<int>& vector) {
    cout << "[";
    for (int i = 0; i < vector.size(); i++) {
        cout << vector.at(i);
        if (i < vector.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

void sumaObjetivo(const int* arr, int n, int objetivo,
                  int inicio, int suma, vector<int>& conjuntoSuma) {
    // Caso base: encontramos una combinación
    if (suma == objetivo) {
        imprimir(conjuntoSuma);
        return;
    }

    for (int i = inicio; i < n; i++) {
        // Poda: el arreglo está ordenado, ningún elemento posterior cabe
        if (suma + arr[i] > objetivo) break;

        // Hacer
        conjuntoSuma.push_back(arr[i]);
        // Explorar: cada elemento puede utilizarse como máximo 1 vez. Por eso i+1.
        sumaObjetivo(arr, n, objetivo, i + 1, suma + arr[i], conjuntoSuma);
        // Deshacer
        conjuntoSuma.pop_back();
        // no deshacemos suma porque se pasa por valor.
        // Si el parámetro estuviera por referencia, sí se realizaría un deshacer
    }
}

int main() {
    int arr[] = {2, 3, 5, 7}; // debe estar ordenado de menor a mayor
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> conjuntoSuma;

    sumaObjetivo(arr, n, 10, 0, 0, conjuntoSuma);

    return 0;
}
