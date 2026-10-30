#include <iostream>
#include <vector>
#include <ctime>        // time
#include <climits>      // INT_MAX e INT_MIN
#include <algorithm>    // min y max
#include <cstdlib>      // srand y rand
using namespace std;

#define CIUDAD_INICIAL 0
#define ALFA 0.3
#define ITERACIONES 1000

struct Ruta{
    vector<int> ciudades;
    int distanciaTotal;
};

vector<int> generarRCL(const vector<vector<int>>& matriz,
                       const vector<bool>& visitado,
                       int ciudadActual) {
    int minimo = INT_MAX;
    int maximo = INT_MIN;

    // Calculamos el máximo y mínimo
    for (int i = 0; i < matriz.size(); i++) {
        int distancia = matriz[ciudadActual][i];
        if (distancia != 0 && !visitado[i]) {
            minimo = min(distancia, minimo);
            maximo = max(distancia, maximo);
        }
    }

    // Definimos el umbral
    double umbral = minimo + ALFA * (maximo - minimo);
    vector<int> rcl;

    // Generamos la RCL
    for (int i = 0; i < matriz.size(); i++) {
        int distancia = matriz[ciudadActual][i];
        if (distancia <= umbral && !visitado[i]) {
            rcl.push_back(i);
        }
    }
    return rcl;
}

Ruta generarRuta(const vector<vector<int>>& matriz,
                 vector<bool>& visitado) {
    vector<int> ruta;
    int ciudadActual = CIUDAD_INICIAL;
    ruta.push_back({CIUDAD_INICIAL});
    visitado[ciudadActual] = true;

    int ciudadesVisitadas = 1;
    int distanciaTotal = 0;

    while (ciudadesVisitadas < matriz.size()) {
        vector<int> rcl = generarRCL(matriz, visitado, ciudadActual);
        int indice = rand() % rcl.size();
        int ciudadElegida = rcl[indice];

        ruta.push_back(ciudadElegida);
        distanciaTotal += matriz[ciudadActual][ciudadElegida];
        ciudadActual = ciudadElegida;

        visitado[ciudadElegida] = true;
        ciudadesVisitadas++;
    }

    ruta.push_back(CIUDAD_INICIAL);
    distanciaTotal += matriz[ciudadActual][CIUDAD_INICIAL];

    return {ruta, distanciaTotal};
}


Ruta generarMejorRuta(const vector<vector<int>>& matriz) {
    Ruta mejorRuta;
    mejorRuta.distanciaTotal = INT_MAX;

    for (int i = 0; i < ITERACIONES; i++) {
        // Inicializamos los estados de las ciudades en cada generación de la ruta
        vector<bool> visitado(matriz.size(), false);
        Ruta ruta = generarRuta(matriz, visitado);
        if (mejorRuta.distanciaTotal > ruta.distanciaTotal) {
            // Nos quedamos con la ruta con menor distancia
            mejorRuta = ruta;
        }
    }
    return mejorRuta;
}

void imprimir(const Ruta& ruta) {
    cout << "Ciudad inicial: " << CIUDAD_INICIAL;
    cout << "\nAlfa: " << ALFA;
    cout << "\nIteraciones: " << ITERACIONES;
    cout << "\n\nMejor ruta: ";
    for (int i = 0; i < ruta.ciudades.size(); i++) {
        if (i != 0) cout << " -> ";
        cout << ruta.ciudades[i];
    }
    cout << "\nDistancia total: " << ruta.distanciaTotal;
}

int main() {
    vector<vector<int>> matriz = {
        {0, 10, 15, 20, 25, 30},
        {10, 0, 35, 12, 28, 40},
        {15, 35, 0, 30, 9, 11},
        {20, 12, 30, 0, 8, 22},
        {25, 28, 9, 8, 0, 18},
        {30, 40, 11, 22, 18, 0},
    };
    srand(time(nullptr));
    Ruta ruta = generarMejorRuta(matriz);
    imprimir(ruta);
    return 0;
}
