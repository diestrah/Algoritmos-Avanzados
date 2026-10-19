/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 31/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

void GenerarParentesisValidos(string& cadena, int pares, int abiertos, int cerrados) {
    // Caso base
    if (abiertos == pares && cerrados == pares) {
        cout << cadena << endl;
        return;
    }

    // Podemos abrir paréntesis si todavía quedan paréntesis
    if (abiertos < pares) {
        cadena.push_back('('); // hacer
        GenerarParentesisValidos(cadena, pares, abiertos + 1, cerrados);
        cadena.pop_back(); // deshacer
    }

    // Podemos cerrar si hay paréntesis abiertos pendientes
    if (cerrados < abiertos) {
        cadena.push_back(')'); // hacer
        GenerarParentesisValidos(cadena, pares, abiertos, cerrados + 1);
        cadena.pop_back(); // deshacer
    }
}

int main() {
    string cadena;
    int cantAbiertos = 0;
    int cantCerrados = 0;
    int pares = 3;

    GenerarParentesisValidos(cadena, pares, cantAbiertos, cantCerrados);

    return 0;
}
