#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <cstdlib>
using namespace std;

#define ALFA 0.3
#define CIUDAD_INICIAL 0

struct Ciudad{
    int indice;
    int distancia; // distancia desde la ciudad anterior
};

struct ResultadoRCL{
    int minimo; // beta
    int maximo; // tau
    double umbral;
    vector<Ciudad> rcl;
};

ResultadoRCL construirRCL(const vector<vector<int>>& matriz, vector<bool> visitadas, int ciudadActual) {
    // Inicializamos los máximos y mínimos
    ResultadoRCL resultado;
    resultado.minimo = INT_MAX;
    resultado.maximo = INT_MIN;

    // Evaluamos solo las ciudades no visitadas
    for (int i = 0; i < matriz[ciudadActual].size(); i++) {
        int distancia = matriz[ciudadActual][i];

        if (distancia != 0 && !visitadas[i]) {
            if (resultado.minimo > distancia) {
                resultado.minimo = distancia;
            }
            if (resultado.maximo < distancia) {
                resultado.maximo = distancia;
            }
        }
    }

    // calculamos el umbral mínimo
    resultado.umbral = resultado.minimo + ALFA * (resultado.maximo - resultado.minimo);

    // Ahora almacenamos los valores dentro del RCL
    for (int i = 0; i < matriz[ciudadActual].size(); i++) {
        if (!visitadas[i] && matriz[ciudadActual][i] <= resultado.umbral) {
            resultado.rcl.push_back(
                {i, matriz.at(ciudadActual)[i]
                });
        }
    }
    return resultado;
}

vector<Ciudad> generarRuta(const vector<vector<int>>& matriz, vector<bool> visitadas) {
    vector<Ciudad> ruta;

    // Empezamos desde la ciudad inicial (definida en el enunciado)
    ruta.push_back({CIUDAD_INICIAL, 0});
    visitadas[CIUDAD_INICIAL] = true;

    int ciudadActual = CIUDAD_INICIAL;
    int ciudadesRecorridas = 1;

    // Mientras la cantidad de ciudades recorridas sea menor a la cantidad de ciudades:
    while (ciudadesRecorridas < matriz.size()) {
        ResultadoRCL resultado = construirRCL(matriz, visitadas, ciudadActual);

        int indice = rand() % resultado.rcl.size();
        Ciudad elegida = resultado.rcl[indice];
        ruta.push_back(elegida);

        visitadas[elegida.indice] = true; // actualizamos el estado
        ciudadActual = elegida.indice; // actualizamos la ciudad

        ciudadesRecorridas++;
    }
    ruta.push_back({
        CIUDAD_INICIAL,
        matriz[ciudadActual][CIUDAD_INICIAL]
    });

    return ruta;
}

void imprimir(const vector<Ciudad>& ruta) {
    int distancia = 0;
    cout << "Ciudad inicial: " << ruta[0].indice << endl;
    cout << "Alfa: " << ALFA << endl;
    cout << "\nRuta: ";
    for (int i = 0; i < ruta.size(); i++) {
        if (i != 0) cout << " -> ";
        cout << ruta[i].indice;
        distancia += ruta[i].distancia;
    }
    cout << "\nDistancia total: " << distancia << endl;
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
    vector<bool> visitadas(matriz.size(), false);
    srand(time(nullptr));

    vector<Ciudad> ruta = generarRuta(matriz, visitadas);
    imprimir(ruta);

    return 0;
}
