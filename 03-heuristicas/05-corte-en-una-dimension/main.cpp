#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define LONGITUD 10

struct Segmento{
    int longitud;
    int cantidad;
};

struct Rollo{
    vector<int> segmentos;
    int merma;
};

bool esMayorLongitud(const Segmento& a, const Segmento& b) {
    return a.longitud > b.longitud;
}

void realizarCortes(Segmento* pedidos, int n, vector<Rollo>& cortes) {
    int pedidosCompletados = 0;

    // Abriremos rollos hasta completar todos los pedidos
    while (pedidosCompletados < n) {
        // Usamos un nuevo rollo
        Rollo rollo;
        rollo.merma = LONGITUD;

        int i = 0;
        while (i < n) {
            if (pedidos[i].cantidad != 0 && rollo.merma >= pedidos[i].longitud) {
                rollo.merma -= pedidos[i].longitud; // actualizamos la longitud de la merma
                rollo.segmentos.push_back(pedidos[i].longitud);

                pedidos[i].cantidad--; // actualizamos la cantidad
                if (pedidos[i].cantidad == 0) {
                    // Si la cantidad de un pedido llega a 0, se completó
                    pedidosCompletados++;
                }
            }
            else {
                // Si todavía quedan unidades y caben, repetiremos este segmento.
                // Por ello, no incrementamos i después de cortar.
                i++;
            }
        }
        cortes.push_back(rollo);
    }
}

void imprimir(const vector<Rollo>& cortes) {
    int mermaTotal = 0;

    for (int i = 0; i < cortes.size(); i++) {
        cout << "Rollo " << i + 1 << ":\n";
        cout << "Segmentos: [";
        for (int j = 0; j < cortes[i].segmentos.size(); j++) {
            if (j != 0) cout << ", ";
            cout << cortes[i].segmentos[j];
        }
        cout << "]\nMerma: " << cortes[i].merma << "m\n\n";
        mermaTotal += cortes[i].merma;
    }

    cout << "Rollos utilizados: " << cortes.size() << "\n";
    cout << "Merma total: " << mermaTotal << "m\n";
}

int main() {
    Segmento pedidos[]{
        {2, 4},
        {3, 2},
        {5, 3},
        {6, 2},
        {8, 2},
    };

    int n = sizeof(pedidos) / sizeof(Segmento);
    // Estrategia: priorizar los segmentos más largos
    sort(pedidos, pedidos + n, esMayorLongitud);

    vector<Rollo> cortes;
    realizarCortes(pedidos, n, cortes);
    imprimir(cortes);

    return 0;
}
