/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 24/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <vector>

using namespace std;

void imprimir(const vector<int>& vector) {
    cout << "[";
    for (size_t i = 0; i < vector.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << vector[i];
    }
    cout << "]\n";
}

void generarSubconjuntos(const vector<int>& elementos, int indice,
                         vector<int>& subconjunto) {
    // Caso base: ya decidimos si incluir o no cada elemento
    if (indice == elementos.size()) {
        imprimir(subconjunto);
        return;
    }

    // Opción 1: incluir el elemento
    subconjunto.push_back(elementos[indice]); // Hacer
    generarSubconjuntos(elementos, indice + 1, subconjunto); // Explorar
    subconjunto.pop_back(); // Deshacer

    // Opción 2: no incluir el elemento.
    // "actual" vuelve a estar como estaba antes de incluirlo.
    generarSubconjuntos(elementos, indice + 1, subconjunto);
}

int main() {
    // Se asume que los elementos son distintos.
    vector<int> elementos = {1, 2, 3};
    vector<int> subconjunto;

    // Empezamos sin elementos y decidimos desde el índice 0.
    generarSubconjuntos(elementos, 0, subconjunto);

    return 0;
}
