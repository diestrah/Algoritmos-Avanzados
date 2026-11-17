#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

#define CANT_GENES 8
#define INDIVIDUOS 6
#define GENERACIONES 5
#define TASA_SELECCION 0.8
#define PROB_MUTAR 0.1

// Un cromosoma binario es una aberracion si no contiene ningun uno
bool esAberracion(const vector<int>& individuo) {
    for (int gen : individuo) {
        if (gen == 1) return false;
    }
    return true;
}

vector<vector<int>> generarPoblacionInicial() {
    vector<vector<int>> poblacion;

    while (poblacion.size() < INDIVIDUOS) {
        vector<int> individuo(CANT_GENES);

        for (int j = 0; j < CANT_GENES; j++) {
            individuo[j] = rand() % 2;
        }

        if (!esAberracion(individuo)) {
            poblacion.push_back(individuo);
        }
    }

    return poblacion;
}

int calcularFitness(const vector<int>& individuo) {
    int fitness = 0;
    for (int gen : individuo) fitness += gen;
    return fitness;
}

vector<int> calcularFitnessAcumulados(const vector<vector<int>>& poblacion) {
    vector<int> fitnessAcumulados;
    int acumulado = 0;

    for (const vector<int>& individuo : poblacion) {
        acumulado += calcularFitness(individuo);
        fitnessAcumulados.push_back(acumulado);
    }

    return fitnessAcumulados;
}

vector<vector<int>> seleccionarPadres(const vector<vector<int>>& poblacion) {

    vector<int> fitnessAcumulados = calcularFitnessAcumulados(poblacion);
    int fitnessTotal = fitnessAcumulados.back();
    int cantidadPadres = (int)round(poblacion.size() * TASA_SELECCION);

    vector<vector<int>> padres;

    for (int i = 0; i < cantidadPadres; i++) {
        int ticket = rand() % fitnessTotal;
        int indice = 0;

        // Busca el primer acumulado estrictamente mayor que el ticket
        while (ticket >= fitnessAcumulados[indice]) {
            indice++;
        }

        padres.push_back(poblacion[indice]);
    }

    return padres;
}

vector<int> cruzarDeUnPunto(const vector<int>& padre,
                            const vector<int>& madre) {
    int cantidadGenes = (int)padre.size();
    int puntoDeCorte = 1 + rand() % (cantidadGenes - 1);

    vector<int> hijo;
    for (int i = 0; i < puntoDeCorte; i++)
        hijo.push_back(padre[i]);
    for (int i = puntoDeCorte; i < cantidadGenes; i++)
        hijo.push_back(madre[i]);

    return hijo;
}

void mutarIndividuo(vector<int>& individuo) {
    for (int i = 0; i < individuo.size(); i++) {
        if (rand() % 100 < PROB_MUTAR * 100) {
            individuo[i] = !individuo[i];
        }
    }
}

// Genera y muta un hijo por cada pareja ordenada de indices distintos.
// Los individuos originales permanecen disponibles para el reemplazo
void generarDescendencia(vector<vector<int>>& poblacion,
                         const vector<vector<int>>& padres) {
    for (int i = 0; i < padres.size(); i++) {
        for (int j = 0; j < padres.size(); j++) {
            if (i != j) {
                vector<int> hijo = cruzarDeUnPunto(padres[i], padres[j]);
                mutarIndividuo(hijo);

                if (!esAberracion(hijo)) {
                    poblacion.push_back(hijo);
                }
            }
        }
    }
}

// Conserva los INDIVIDUOS mejores entre la poblacion actual y los hijos.
// (se permiten cromosomas repetidos)
void seleccionarSupervivientes(vector<vector<int>>& poblacion) {
    sort(poblacion.begin(), poblacion.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return calcularFitness(a) > calcularFitness(b);
         });

    if (poblacion.size() > INDIVIDUOS) {
        poblacion.erase(poblacion.begin() + INDIVIDUOS, poblacion.end());
    }
}

void imprimirIndividuo(const vector<int>& individuo) {
    for (int gen : individuo) cout << gen << " ";
    cout << endl;
}

int main() {
    srand(time(nullptr));

    vector<vector<int>> poblacion = generarPoblacionInicial();
    seleccionarSupervivientes(poblacion);
    vector<int> mejorIndividuo = poblacion.front();
    int mejorFitness = calcularFitness(mejorIndividuo);
    cout << "Generacion 0 | Mejor fitness: " << mejorFitness << endl;

    for (int generacion = 1; generacion <= GENERACIONES; generacion++) {
        vector<vector<int>> padres = seleccionarPadres(poblacion);

        generarDescendencia(poblacion, padres);
        seleccionarSupervivientes(poblacion);
        int fitnessActual = calcularFitness(poblacion.front());
        cout << "Generacion " << generacion
            << " | Mejor fitness: " << fitnessActual << endl;

        // Conserva el primer mejor individuo encontrado en caso de empate.
        if (fitnessActual > mejorFitness) {
            mejorFitness = fitnessActual;
            mejorIndividuo = poblacion.front();
        }
    }

    cout << "\nMejor cromosoma encontrado: ";
    imprimirIndividuo(mejorIndividuo);
    cout << "Mejor fitness encontrado: " << mejorFitness << endl;

    return 0;
}
