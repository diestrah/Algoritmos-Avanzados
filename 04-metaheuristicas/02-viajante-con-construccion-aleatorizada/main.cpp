#include <iostream>
#include <vector>
#include <algorithm>    // max(), min()
#include <climits>      // INT_MAX, INT_MIN
#include <ctime>        // time()
#include <cstdlib>      // srand(), rand()
using namespace std;

#define ALFA 0.3
#define CIUDAD_INICIAL 0

struct Ruta{
    vector<int> ciudades;
    int distanciaTotal;
};

vector<int> construirRCL(const vector<vector<int>>& matriz,
                         const vector<bool>& visitadas, int ciudadActual) {
    // Inicializamos los máximos y mínimos
    int minimo = INT_MAX;
    int maximo = INT_MIN;

    // Evaluamos solo las ciudades no visitadas
    for (int i = 0; i < matriz[ciudadActual].size(); i++) {
        int distancia = matriz[ciudadActual][i];
        if (distancia != 0 && !visitadas[i]) {
            minimo = min(minimo, distancia);
            maximo = max(maximo, distancia);
        }
    }

    // Distancia máxima que aceptará la RCL
    double umbral = minimo + ALFA * (maximo - minimo);
    vector<int> rcl;

    // Ahora almacenamos los índices válidos dentro del RCL
    for (int i = 0; i < matriz[ciudadActual].size(); i++) {
        int distancia = matriz[ciudadActual][i];
        if (!visitadas[i] && distancia <= umbral &&
            distancia != 0) {
            rcl.push_back(i);
        }
    }
    return rcl;
}

Ruta generarRuta(const vector<vector<int>>& matriz) {
    vector<bool> visitadas(matriz.size(), false);
    Ruta ruta{{}, 0};

    // Empezamos desde la ciudad inicial (definida en el enunciado)
    ruta.ciudades.push_back(CIUDAD_INICIAL);
    visitadas[CIUDAD_INICIAL] = true;

    int ciudadActual = CIUDAD_INICIAL;
    int ciudadesRecorridas = 1;

    // Mientras la cantidad de ciudades recorridas sea menor a la cantidad de ciudades:
    while (ciudadesRecorridas < matriz.size()) {
        vector<int> rcl = construirRCL(matriz, visitadas, ciudadActual);
        int indice = rand() % rcl.size();
        int ciudadElegida = rcl[indice];

        // Construimos la ruta
        ruta.ciudades.push_back(ciudadElegida);
        ruta.distanciaTotal += matriz[ciudadActual][ciudadElegida];

        visitadas[ciudadElegida] = true; // actualizamos el estado
        ciudadActual = ciudadElegida; // actualizamos la ciudad
        ciudadesRecorridas++;
    }

    ruta.ciudades.push_back(CIUDAD_INICIAL);
    ruta.distanciaTotal += matriz[ciudadActual][CIUDAD_INICIAL];

    return ruta;
}

void imprimir(const Ruta& ruta) {
    cout << "Ciudad inicial: " << CIUDAD_INICIAL << endl;
    cout << "Alfa: " << ALFA << endl;

    cout << "\nRuta: ";
    for (int i = 0; i < ruta.ciudades.size(); i++) {
        if (i != 0) cout << " -> ";
        cout << ruta.ciudades[i];
    }
    cout << "\nDistancia total: " << ruta.distanciaTotal << endl;
}

int main() {
    const vector<vector<int>> matriz = {
        {0, 10, 15, 20, 25, 30},
        {10, 0, 35, 12, 28, 40},
        {15, 35, 0, 30, 9, 11},
        {20, 12, 30, 0, 8, 22},
        {25, 28, 9, 8, 0, 18},
        {30, 40, 11, 22, 18, 0},
    };
    srand(time(nullptr));
    Ruta ruta = generarRuta(matriz);
    imprimir(ruta);
    return 0;
}
