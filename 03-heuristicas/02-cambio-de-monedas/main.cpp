#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generarCambioMonedas(const vector<int>& monedas,
                          int& montoPendiente,
                          vector<int>& cambio) {
    int indice = 0;
    while (montoPendiente > 0 && indice < monedas.size()) {
        if (monedas[indice] <= montoPendiente) {
            montoPendiente -= monedas[indice];
            cambio.push_back(monedas[indice]);
        } else {
            indice++;
        }
    }
}

void imprimir(const vector<int>& cambio, int monto) {
    cout << "Monedas seleccionadas: [";
    bool notFirst = false;
    for (int moneda : cambio) {
        if (notFirst) cout << ", ";
        cout << moneda;
        notFirst = true;
    }
    cout << "]\nCantidad de monedas: " << cambio.size() << endl;
    cout << "Monto pendiente: " << monto << endl;

    if (monto > 0) {
        cout << "La heurística no logró completar el cambio" << endl;
    }
}

int main() {
    vector monedas = {5, 20, 1, 13};
    sort(monedas.rbegin(), monedas.rend());
    int monto = 39;
    vector<int> cambio;

    generarCambioMonedas(monedas, monto, cambio);
    imprimir(cambio, monto);

    return 0;
}
