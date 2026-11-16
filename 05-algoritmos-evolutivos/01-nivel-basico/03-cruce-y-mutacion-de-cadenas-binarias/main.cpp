#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define PROB_MUTAR 0.1

void imprimirIndividuo(const vector<int>& individuo) {
    for (int i = 0; i < individuo.size(); i++)
        cout << individuo[i] << " ";
    cout << endl;
}

void mutarIndividuo(vector<int>& hijo) {
    for (int i = 0; i < hijo.size(); i++) {
        // Si estamos dentro del cuantil para la mutacion, invertimos el gen
        if (rand() % 100 < PROB_MUTAR * 100) {
            hijo[i] = !hijo[i];
        }
    }
}

// Genera dos hijos intercambiando los segmentos finales de los padres
vector<int> cruceDeUnPunto(const vector<int>& padre,
                           const vector<int>& madre) {
    int cantidadGenes = (int)padre.size();
    // El corte deja al menos un gen a cada lado
    int puntoDeCorte = 1 + rand() % (cantidadGenes - 1);
    cout << "Punto de corte: " << puntoDeCorte << endl;

    vector<int> hijo;
    for (int i = 0; i < puntoDeCorte; i++)
        hijo.push_back(padre[i]);
    for (int i = puntoDeCorte; i < madre.size(); i++)
        hijo.push_back(madre[i]);

    return hijo;
}

// Genera dos hijos eligiendo el origen de cada gen aleatoriamente
vector<int> cruceUniforme(const vector<int>& padre,
                          const vector<int>& madre) {
    vector<int> hijo;
    int cantidadGenes = padre.size();

    for (int i = 0; i < cantidadGenes; i++) {
        int gen = rand() % 2 ? padre[i] : madre[i];
        hijo.push_back(gen);
    }

    return hijo;
}

int main() {
    srand(time(nullptr));
    vector<int> padre{1, 1, 0, 0, 1, 0};
    vector<int> madre{0, 0, 1, 1, 0, 1};
    vector<int> hijo;

    cout << "Padre: ";
    imprimirIndividuo(padre);
    cout << "Madre: ";
    imprimirIndividuo(madre);

    // Cruce de un punto
    cout << "\nCruce de un punto:" << endl;
    hijo = cruceDeUnPunto(padre, madre);

    cout << "\nAntes de mutar:" << endl;
    imprimirIndividuo(hijo);

    mutarIndividuo(hijo);
    cout << "\nDespues de mutar:" << endl;
    imprimirIndividuo(hijo);

    // Cruce uniforme
    cout << "\nCruce uniforme:" << endl;
    hijo = cruceUniforme(padre, madre);

    cout << "\nAntes de mutar:" << endl;
    imprimirIndividuo(hijo);

    mutarIndividuo(hijo);
    cout << "\nDespues de mutar:" << endl;
    imprimirIndividuo(hijo);

    return 0;
}
