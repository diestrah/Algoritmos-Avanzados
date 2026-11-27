#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

#define TAM_POBLACION 6
#define ITERACIONES 100
#define TASA_SELECCION 0.8
#define PROB_MUTACION 0.1
#define PUNTO_CORTE 0.5

void mataclon(vector<vector<vector<int>>>& poblacion) {
    map<vector<vector<int>>, bool> unicos;
    for (const auto& individuo : poblacion) {
        unicos[individuo] = true;
    }

    poblacion.clear();

    for (const auto& elemento : unicos) {
        poblacion.push_back(elemento.first);
    }
}

vector<int> generarIndices(const vector<vector<int>>& ganancias) {
    map<int, bool> orden;
    int cant = 0;
    while (cant < ganancias.size()) {
        int pos = rand() % ganancias.size();
        if (orden[pos] == false) {
            orden[pos] = true;
            cant++;
        }
    }

    vector<int> indices;
    for (const auto& elemento : orden) {
        indices.push_back(elemento.first);
    }
    return indices;
}

vector<vector<vector<int>>> generarPoblacion(const vector<vector<int>>& ganancias) {
    vector<vector<vector<int>>> poblacion;
    while (poblacion.size() < TAM_POBLACION) {
        vector<vector<int>> individuo(ganancias.size(), vector<int>(ganancias.size(), 0));
        vector<int> orden = generarIndices(ganancias);
        for (int i = 0; i < orden.size(); i++) {
            individuo[i][orden[i]] = 1;
        }
        poblacion.push_back(individuo);
        mataclon(poblacion);
    }
    return poblacion;
}

int calcularFitness(const vector<vector<int>>& ganancias,
                    const vector<vector<int>> individuo) {
    int fitness = 0;
    for (int i = 0; i < individuo.size(); i++) {
        for (int j = 0; j < individuo[i].size(); j++) {
            if (individuo[i][j]) {
                fitness += ganancias[i][j];
            }
        }
    }
    return fitness;
}

vector<int> generarFitnessAcumulado(const vector<vector<int>>& ganancias,
                                    vector<vector<vector<int>>> poblacion) {
    vector<int> fitnessAcumulado;
    int acumulado = 0;
    for (int i = 0; i < poblacion.size(); i++) {
        acumulado += calcularFitness(ganancias, poblacion[i]);
        fitnessAcumulado.push_back(acumulado);
    }
    return fitnessAcumulado;
}

vector<vector<vector<int>>> seleccionarPadres(const vector<vector<int>>& ganancias,
                                              vector<vector<vector<int>>>& poblacion) {
    vector<vector<vector<int>>> padres;
    vector<int> fitnessAcumulado = generarFitnessAcumulado(ganancias, poblacion);
    int cantPadres = (int)round(TAM_POBLACION * poblacion.size());

    for (int i = 0; i < cantPadres; i++) {
        int ticket = rand() % fitnessAcumulado.back();
        int indice = 0;

        while (ticket >= fitnessAcumulado[indice]) {
            indice++;
        }

        padres.push_back(poblacion[indice]);
    }

    return padres;
}

vector<vector<int>> generarHijo(const vector<vector<int>>& padre,
                                const vector<vector<int>>& madre) {
    vector<vector<int>> hijo;
    int puntoCorte = (int)round(padre.size() * PUNTO_CORTE);
    for (int i = 0; i < puntoCorte; i++) {
        hijo.push_back(padre[i]);
    }
    for (int i = puntoCorte; i < padre.size(); i++) {
        hijo.push_back(madre[i]);
    }
    return hijo;
}

bool esAberracion(const vector<vector<int>>& individuo) {
    vector<int> repeticiones(individuo[0].size(), 0);

    for (int i = 0; i < individuo.size(); i++) {
        for (int j = 0; j < individuo[i].size(); j++) {
            if (individuo[i][j]) {
                repeticiones[j]++;
            }
        }
    }

    for (int i : repeticiones) {
        if (i != 1) return true;
    }
    return false;
}

void casamiento(const vector<vector<int>>& ganancias,
                vector<vector<vector<int>>>& poblacion,
                const vector<vector<vector<int>>>& padres) {
    for (int i = 0; i < padres.size(); i++) {
        for (int j = 0; j < padres.size(); j++) {
            if (i != j) {
                vector<vector<int>> hijo = generarHijo(poblacion[i], poblacion[j]);
                if (!esAberracion(hijo)) {
                    poblacion.push_back(hijo);
                }
            }
        }
    }
}

void regenerarPoblacion(const vector<vector<int>>& ganancias,
                        vector<vector<vector<int>>>& poblacion) {
    mataclon(poblacion);

    sort(poblacion.begin(), poblacion.end(),
         [ganancias](const vector<vector<int>>& a, const vector<vector<int>>& b) {
             int fA = calcularFitness(ganancias, a);
             int fB = calcularFitness(ganancias, b);
             return fA > fB;
         });

    if (poblacion.size() > TAM_POBLACION) {
        poblacion.erase(poblacion.begin() + TAM_POBLACION, poblacion.end());
    }
}

void imprimirAsignacion(const vector<vector<int>>& ganancias,
                        const vector<vector<int>>& individuo) {
    cout << "Mejor cromosoma encontrado" << endl;

    cout << "Asignaciones: " << endl;

    cout << "Ganancia total: " << endl;
}


void asignarTareas(const vector<vector<int>>& ganancias) {
    vector<vector<vector<int>>> poblacion = generarPoblacion(ganancias);
    for (int i = 0; i < ITERACIONES; i++) {
        vector<vector<vector<int>>> padres =
            seleccionarPadres(ganancias, poblacion);
        casamiento(ganancias, poblacion, padres);
        regenerarPoblacion(ganancias, poblacion);
    }
    imprimirAsignacion(ganancias, poblacion.front());
}


int main() {
    const vector<vector<int>> ganancias{
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4},
    };

    asignarTareas(ganancias);

    return 0;
}
