/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 24/08/2026
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

bool estaEnElArray(int num, const vector<int>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        if (num == vector[i]) return true;
    }
    return false;
}


void generarPermutaciones(int elementos[], int n, vector<int>& permutacion) {
    // Caso base: se construyó una permutación completa
    if (permutacion.size() == n) {
        imprimir(permutacion);
        return;
    }

    for (int i = 0; i < n; i++) {
        // Solo se utilizan elementos que aún no formen parte de la permutación
        if (!estaEnElArray(elementos[i], permutacion)) {
            // Hacer: agregar el elemento
            permutacion.push_back(elementos[i]);
            // Explorar: completar la permutación para esa eleccion
            generarPermutaciones(elementos, n, permutacion);
            // Deshacer: deshacer el elemento
            permutacion.pop_back();
        }
    }
}

int main() {
    int elementos[] = {1, 2, 3};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    vector<int> permutacion;

    generarPermutaciones(elementos, n, permutacion);

    return 0;
}
