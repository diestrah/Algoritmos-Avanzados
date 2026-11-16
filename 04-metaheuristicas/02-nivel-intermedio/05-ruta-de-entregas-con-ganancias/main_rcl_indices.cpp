#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // min(), max()
#include <climits>      // INT_MIN, INT_MAX
#include <ctime>        // time()
#include <cstdlib>      // rand(), srand()

using namespace std;

#define ITERACIONES 1000
#define ALFA 0.4
#define INICIO 'A'

struct Ruta{
    string recorrido;
    int gananciaTotal;
};

vector<int> construirRCL(const vector<vector<int>>& matriz,
                         const vector<int>& ganancias,
                         const vector<bool>& visitadas,
                         int ciudadActual) {
    int minimo = INT_MAX;
    int maximo = INT_MIN;

    for (int i = 0; i < matriz.size(); i++) {
        int conexion = matriz[ciudadActual][i];
        if (conexion == 1 && !visitadas[i]) {
            minimo = min(minimo, ganancias[i]);
            maximo = max(maximo, ganancias[i]);
        }
    }

    if (minimo == INT_MAX) return {};

    double umbral = maximo - ALFA * (maximo - minimo);
    vector<int> rcl;

    for (int i = 0; i < matriz.size(); i++) {
        int conexion = matriz[ciudadActual][i];
        if (conexion == 1 && !visitadas[i] &&
            ganancias[i] >= umbral) {
            rcl.push_back(i);
        }
    }
    return rcl;
}

Ruta generarRuta(const vector<vector<int>>& matriz,
                 const vector<int>& ganancias) {
    vector<bool> visitadas(ganancias.size(), false);
    Ruta ruta{string(1, INICIO), 0};

    int ciudadActual = INICIO - 'A';
    visitadas[ciudadActual] = true;

    while (true) {
        vector<int> rcl = construirRCL(matriz, ganancias, visitadas, ciudadActual);
        if (rcl.empty()) break;

        int posicion = rand() % rcl.size();
        int siguienteCiudad = rcl[posicion];

        ruta.recorrido += " -> ";
        ruta.recorrido += (char)('A' + siguienteCiudad);
        ruta.gananciaTotal += ganancias[siguienteCiudad];
        ciudadActual = siguienteCiudad;
        visitadas[ciudadActual] = true;
    }

    return ruta;
}

Ruta buscarMejorRuta(const vector<vector<int>>& matriz,
                      const vector<int>& ganancias) {
    Ruta mejorRuta = {"", INT_MIN};
    for (int i = 0; i < ITERACIONES; i++) {
        Ruta ruta = generarRuta(matriz, ganancias);
        if (mejorRuta.gananciaTotal < ruta.gananciaTotal) {
            mejorRuta = ruta;
        }
    }
    return mejorRuta;
}


void imprimir(const Ruta& ruta) {
    cout << "Punto inicial: " << INICIO << endl;
    cout << "Alfa: " << ALFA << endl;
    cout << "Iteraciones: " << ITERACIONES << endl;

    cout << "\nMejor ruta: " << ruta.recorrido << endl;
    cout << "Ganancia total " << ruta.gananciaTotal << endl;
}

int main() {
    const vector<vector<int>> matriz = {
        {0, 1, 1, 1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    const vector<int> ganancias = {0, 20, 30, 40, 40, 40, 10, 50};
    srand(time(nullptr));
    Ruta ruta = buscarMejorRuta(matriz, ganancias);
    imprimir(ruta);
    return 0;
}
