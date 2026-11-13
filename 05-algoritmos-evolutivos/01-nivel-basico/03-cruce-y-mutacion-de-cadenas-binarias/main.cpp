#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define PROBABILIDAD_CRUCE 1.0
#define PROBABILIDAD_MUTACION 0.1

void mutarHijos(vector<vector<int>>& hijos) {
    for (int i = 0; i < hijos.size(); i++) {
        for (int j = 0; j < hijos[i].size(); j++) {
            // Si estamos dentro del cuantil para la mutacion, invertimos el gen
            if (rand() % 100 < PROBABILIDAD_MUTACION * 100) {
                hijos[i][j] = !hijos[i][j];
            }
        }
    }
}

void imprimirIndividuo(const vector<int>& individuo) {
    for (int i = 0; i < individuo.size(); i++) {
        cout << individuo[i] << " ";
    }
    cout << endl;
}

void imprimirHijos(const vector<vector<int>>& hijos) {
    for (int i = 0; i < hijos.size(); i++) {
        cout << "Hijo " << i + 1 << ": ";
        imprimirIndividuo(hijos[i]);
    }
}

// Genera dos hijos intercambiando los segmentos finales de los padres
vector<vector<int>> cruceDeUnPunto(const vector<vector<int>>& padres) {
    // Sin cruce, los hijos son copias de los padres
    if (rand() % 100 >= PROBABILIDAD_CRUCE * 100) {
        cout << "No se realizo el cruce." << endl;
        return padres;
    }

    int cantidadGenes = padres[0].size();

    // El corte deja al menos un gen a cada lado
    int puntoDeCorte = 1 + rand() % (cantidadGenes - 1);
    cout << "Punto de corte: " << puntoDeCorte << endl;

    vector<int> hijo1;
    vector<int> hijo2;

    for (int i = 0; i < cantidadGenes; i++) {
        if (i < puntoDeCorte) {
            hijo1.push_back(padres[0][i]);
            hijo2.push_back(padres[1][i]);
        }
        else {
            hijo1.push_back(padres[1][i]);
            hijo2.push_back(padres[0][i]);
        }
    }

    return {hijo1, hijo2};
}

// Genera dos hijos eligiendo el origen de cada gen aleatoriamente
vector<vector<int>> cruceUniforme(const vector<vector<int>>& padres) {
    // Sin cruce, los hijos son copias de los padres.
    if (rand() % 100 >= PROBABILIDAD_CRUCE * 100) {
        cout << "No se realizo el cruce." << endl;
        return padres;
    }

    int cantidadGenes = padres[0].size();
    vector<int> hijo1;
    vector<int> hijo2;

    for (int i = 0; i < cantidadGenes; i++) {
        int indicePadre = rand() % 2; // 2 representa la cantidad de padres

        // Si un hijo hereda del padre a, el otro hereda del padre b
        int indiceOtroPadre = 1 - indicePadre;

        hijo1.push_back(padres[indicePadre][i]);
        hijo2.push_back(padres[indiceOtroPadre][i]);
    }

    return {hijo1, hijo2};
}

int main() {
    srand(time(nullptr));

    vector<vector<int>> padres{
        {1, 1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1}
    };

    cout << "Padres:" << endl;
    for (int i = 0; i < padres.size(); i++) {
        cout << "Padre " << i + 1 << ": ";
        imprimirIndividuo(padres[i]);
    }

    cout << "\nCruce de un punto:" << endl;
    vector<vector<int>> hijos = cruceDeUnPunto(padres);

    cout << "\nAntes de mutar:" << endl;
    imprimirHijos(hijos);

    mutarHijos(hijos);
    cout << "\nDespues de mutar:" << endl;
    imprimirHijos(hijos);

    cout << "\nCruce uniforme:" << endl;
    hijos = cruceUniforme(padres);

    cout << "\nAntes de mutar:" << endl;
    imprimirHijos(hijos);

    mutarHijos(hijos);
    cout << "\nDespues de mutar:" << endl;
    imprimirHijos(hijos);

    return 0;
}
