#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define N 6 // cantidad de ciudades

void generarRutaMasCorta(int matriz[][N], int* estados, vector<int>& ruta, int& distancia) {
    int ciudadInicial = 0;
    int ciudadActual = ciudadInicial;

    // Partimos de la ciudad inicial
    estados[ciudadInicial] = 1;
    ruta.push_back(ciudadInicial);

    // Recorremos todas las ciudades
    for (int i = 0; i < N - 1; i++) {
        int distanciaMasCorta = INT_MAX;
        int siguienteCiudad = -1;

        // Evaluamos todas las rutas que posee esta ciudad (desde j=1)
        for (int j = 0; j < N; j++) {
            if (estados[j] == 0 && matriz[ciudadActual][j] > 0 &&
                matriz[ciudadActual][j] < distanciaMasCorta) {
                distanciaMasCorta = matriz[ciudadActual][j];
                siguienteCiudad = j;
            }
        }


        estados[siguienteCiudad] = 1; // Marcamos acciones
        ruta.push_back(siguienteCiudad); // Agregamos ciudad
        distancia += matriz[ciudadActual][siguienteCiudad]; // Actualizamos distancias

        ciudadActual = siguienteCiudad;
    }

    // Volvemos a la ciudad inicial
    ruta.push_back(ciudadInicial);
    distancia += matriz[ciudadActual][ciudadInicial];
}

void imprimir(const vector<int>& ruta, int distancia) {
    bool inicio = false;
    for (int i = 0; i < ruta.size(); i++) {
        if (inicio) cout << " -> ";
        cout << ruta.at(i);
        inicio = true;
    }
    cout << endl;
    cout << "La distancia recorrida es: " << distancia << endl;
}


int main() {
    int matriz[N][N]{
        {0, 10, 15, 20, 25, 30},
        {10, 0, 35, 12, 28, 40},
        {15, 35, 0, 30, 9, 11},
        {20, 12, 30, 0, 8, 22},
        {25, 28, 9, 8, 0, 18},
        {30, 40, 11, 22, 18, 0},
    };
    int estados[N] = {}; // Si el estado es 0, no se recorrio; si es 1, se recorrio
    int distancia = 0;
    vector<int> ruta;

    generarRutaMasCorta(matriz, estados, ruta, distancia);
    imprimir(ruta, distancia);

    return 0;
}
