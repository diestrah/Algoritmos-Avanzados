/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 27/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <vector>

using namespace std;

void imprimir(const vector<int>& cambio) {
    cout << "[";
    for (int i = 0; i < cambio.size(); i++) {
        cout << cambio[i];
        if (i < cambio.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

void cambioDeMonedas(int monedas[], int n, int monto, int inicio,
                     int suma, vector<int>& cambio) {
    // Caso base: encontramos una solución
    if (suma == monto) {
        imprimir(cambio);
        return;
    }

    // Probamos todas las monedas desde el inicio
    for (int i = inicio; i < n; i++) {
        // Poda: la moneda actual supera lo que falta.
        // Como el arreglo de monedas está ordenado, las siguientes tampoco caben.
        if (monedas[i] > monto - suma) break;

        // Hacer
        cambio.push_back(monedas[i]);
        // Explorar
        cambioDeMonedas(monedas, n, monto, i, suma + monedas[i], cambio);
        // Deshacer
        cambio.pop_back();
    }
}

int main() {
    int monedas[] = {1, 2, 5};
    int n = sizeof(monedas) / sizeof(monedas[0]);
    int monto = 5;
    vector<int> cambio;

    cambioDeMonedas(monedas, n, monto, 0, 0, cambio);

    return 0;
}
