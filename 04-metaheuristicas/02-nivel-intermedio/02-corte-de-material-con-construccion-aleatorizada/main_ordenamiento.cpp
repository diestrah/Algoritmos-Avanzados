#include <iostream>
#include <vector>
#include <algorithm>    // min(), max()
#include <climits>      // INT_MIN, INT_MAX
#include <ctime>        // time()
#include <cstdlib>      // srand(), rand()
using namespace std;

#define ALFA 0.3
#define LONGITUD 10
#define ITERACIONES 1000

struct Segmento{
    int longitud;
    int cantidad;
};

struct Rollo{
    vector<int> segmentos;
    int merma = LONGITUD;
};

struct Construccion{
    vector<Rollo> rollos;
    int mermaTotal = 0;
};

bool mayorLongitud(const Segmento& a, const Segmento& b) {
    return a.longitud > b.longitud;
}

void eliminarPedidosCompletados(vector<Segmento>& pendientes) {
    for (int i = 0; i < pendientes.size();) {
        if (pendientes[i].cantidad == 0) {
            pendientes.erase(pendientes.begin() + i);
        }
        else {
            i++;
        }
    }
}

int contarCandidatosRCL(const vector<Segmento>& pendientes,
                        int inicio, double umbral) {
    int cantidad = 0;
    while (inicio + cantidad < pendientes.size() &&
        pendientes[inicio + cantidad].longitud >= umbral) {
        cantidad++;
    }
    return cantidad;
}


int buscarSegmentoQueCabe(const vector<Segmento>& pendientes, int merma) {
    int ind = 0;
    for (int i = 0; i < pendientes.size(); i++) {
        if (pendientes[i].longitud > merma) {
            ind++;
        }
    }
    return ind;
}

Construccion cortarMaterial(const vector<Segmento>& segmentos) {
    Construccion construccion;

    // Copiamos los segmentos para utilizarlas en esta construcción
    // La copia ya se encuentra ordenada descendentemente por longitud
    vector<Segmento> pendientes = segmentos;

    // Abrimos rollos hasta satisfacer todo el pedido
    while (!pendientes.empty()) {
        Rollo rollo;

        // Mientras exista algún segmento pendiente que quepa, cortamos el rollo actual
        while (true) {
            eliminarPedidosCompletados(pendientes);
            if (pendientes.empty()) break;

            int inicio = buscarSegmentoQueCabe(pendientes, rollo.merma);
            // Si ningun segmento cabe, se cierra el rollo
            if (inicio == pendientes.size()) break;

            int beta = pendientes[inicio].longitud;
            int tau = pendientes.back().longitud;
            double umbral = beta - ALFA * (beta - tau);

            int cantidadRCL = contarCandidatosRCL(pendientes, inicio, umbral);

            // Elegimos dentro de la RCL y convertimos a una posición en pendientes
            int posicion = rand() % cantidadRCL + inicio;
            int longitud = pendientes[posicion].longitud;

            rollo.merma -= longitud;
            rollo.segmentos.push_back(longitud);
            pendientes[posicion].cantidad--;
        }

        construccion.mermaTotal += rollo.merma;
        construccion.rollos.push_back(rollo);
    }

    return construccion;
}

Construccion seleccionarMejorCorte(const vector<Segmento>& segmentos) {
    Construccion mejorCorte;
    mejorCorte.mermaTotal = INT_MAX;
    for (int i = 0; i < ITERACIONES; i++) {
        // Cada construcción reinicia las cantidades y los rollos utilizados
        Construccion corte = cortarMaterial(segmentos);

        // Elegimos la construcción que tenga la menor merma
        if (corte.mermaTotal < mejorCorte.mermaTotal) {
            mejorCorte = corte;
        }
    }
    return mejorCorte;
}

void imprimir(const Construccion& cortes) {
    cout << "Longitud de cada rollo: " << LONGITUD << endl;
    cout << "Alfa: " << ALFA << endl;
    cout << "Iteraciones: " << ITERACIONES << endl;

    for (int i = 0; i < cortes.rollos.size(); i++) {
        cout << "\nRollo " << i + 1 << ":" << endl;
        cout << "Segmentos: [";

        bool coma = false;
        for (auto r : cortes.rollos[i].segmentos) {
            if (coma) cout << ", ";
            cout << r;
            coma = true;
        }

        cout << "]\nMerma: " << cortes.rollos[i].merma << " m" << endl;
    }

    cout << "\nRollos utilizados: " << cortes.rollos.size() << endl;
    cout << "Merma total: " << cortes.mermaTotal << " m" << endl;
}

int main() {
    vector<Segmento> segmentos = {
        {2, 4},
        {3, 2},
        {5, 3},
        {6, 2},
        {8, 2},
    };

    srand(time(nullptr));
    sort(segmentos.begin(), segmentos.end(), mayorLongitud);

    Construccion cortes = seleccionarMejorCorte(segmentos);
    imprimir(cortes);

    return 0;
}
