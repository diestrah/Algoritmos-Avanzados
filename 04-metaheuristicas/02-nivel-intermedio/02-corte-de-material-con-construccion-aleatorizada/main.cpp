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

vector<int> generarRCL(const vector<Segmento>& segmentos,
                       const vector<int>& cantidades,
                       int espacioDisponible) {
    int minimo = INT_MAX;
    int maximo = INT_MIN;
    // Calculamos los extremos entre las longitudes pendientes que caben
    for (int i = 0; i < (int)segmentos.size(); i++) {
        if (cantidades[i] > 0 &&
            segmentos[i].longitud <= espacioDisponible) {
            minimo = min(minimo, segmentos[i].longitud);
            maximo = max(maximo, segmentos[i].longitud);
        }
    }

    // Si no hay candidatos, se termina de cortar el rollo actual
    if (maximo == INT_MIN) return {};

    // Favorecemos las longitudes mayores: establecemos la mínima aceptada
    double umbral = maximo - ALFA * (maximo - minimo);
    vector<int> rcl;

    for (int i = 0; i < (int)segmentos.size(); i++) {
        if (cantidades[i] > 0 &&
            segmentos[i].longitud <= espacioDisponible &&
            segmentos[i].longitud >= umbral) {
            // Guardamo los índices de los pedidos aceptados en la RCL
            rcl.push_back(i);
        }
    }

    return rcl;
}


Construccion cortarMaterial(const vector<Segmento>& segmentos) {
    vector<int> cantidades;
    int segmentosPendientes = 0;

    // Copiamos las cantidades de los segmentos para utilizarlas en esta construcción
    for (const Segmento& segmento : segmentos) {
        cantidades.push_back(segmento.cantidad);
        segmentosPendientes += segmento.cantidad;
    }

    Construccion construccion;

    // Abrimos rollos hasta satisfacer todo el pedido
    while (segmentosPendientes > 0) {
        Rollo rollo;

        // Mientras exista algún segmento pendiente que quepa, cortamos el rollo actual
        while (true) {
            vector<int> rcl = generarRCL(segmentos, cantidades, rollo.merma);
            if (rcl.empty()) break;

            // La posición pertenece a la RCL. El índice identifica el pedido original
            int posicion = rand() % rcl.size();
            int indice = rcl[posicion];
            int longitud = segmentos[indice].longitud;

            rollo.merma -= longitud;
            rollo.segmentos.push_back(longitud);
            cantidades[indice]--;
            segmentosPendientes--;
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
    Construccion cortes = seleccionarMejorCorte(segmentos);
    imprimir(cortes);
    return 0;
}
