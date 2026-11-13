#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define CANTIDAD_GENES 6
#define INDIVIDUOS 5

vector<vector<int>> generarPoblacion() {
    vector<vector<int>> poblacion;

    for (int i = 0; i < INDIVIDUOS; i++) {
        vector<int> individuo;

        for (int j = 0; j < CANTIDAD_GENES; j++) {
            int gen = rand() % 2;
            individuo.push_back(gen);
        }

        poblacion.push_back(individuo);
    }

    return poblacion;
}

void imprimirIndividuo(const vector<int>& individuo) {
    for (int i = 0; i < individuo.size(); i++) {
        cout << individuo[i] << " ";
    }
}

int calcularFitness(const vector<int>& individuo) {
    int fitness = 0;
    for (int i = 0; i < individuo.size(); i++) {
        fitness += individuo[i];
    }
    return fitness;
}

void imprimirPoblacion(const vector<vector<int>>& poblacion) {
    cout << "Poblacion inicial: " << endl;

    for (int i = 0; i < poblacion.size(); i++) {
        cout << "Individuo " << i + 1 << ": ";
        imprimirIndividuo(poblacion[i]);
        int fitness = calcularFitness(poblacion[i]);
        cout << "| Fitness: " << fitness << endl;
    }

}

void imprimirMejorIndividuo(const vector<vector<int>>& poblacion) {
    int mejorFitness = -1;
    int mejorIndividuo = -1;

    for (int i = 0; i < poblacion.size(); i++) {
        int fitness = calcularFitness(poblacion[i]);
        if (mejorFitness < fitness) {
            mejorFitness = fitness;
            mejorIndividuo = i;
        }
    }

    cout << "\nMejor individuo: " << mejorIndividuo + 1 << endl;
    cout << "Cromosoma: ";
    imprimirIndividuo(poblacion[mejorIndividuo]);
    cout << "\nFitness: " << mejorFitness << endl;
}

int main() {
    srand(time(nullptr));
    vector<vector<int>> poblacion = generarPoblacion();

    imprimirPoblacion(poblacion);
    imprimirMejorIndividuo(poblacion);

    return 0;
}
