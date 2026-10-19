/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 26/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

void imprimir(const string& cadena) {
    cout << cadena << "\n";
}

void generarCadenasBinarias(string& cadena, int bits) {
    // Caso base: se terminó de construir la cadena binaria con n bits
    if (cadena.size() == bits) return;

    for (int i = 0; i < 2; i++) {
        // Hacer
        cadena.push_back('0' + i);
        // Explorar
        generarCadenasBinarias(cadena, bits);
        // Deshacer
        cadena.pop_back();
    }
}

int main() {
    string cadena;
    int bits = 3;

    generarCadenasBinarias(cadena, bits);
    imprimir(cadena);

    return 0;
}
