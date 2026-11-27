#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

#define ITERACIONES 5
#define TAM_POBLACION 10
#define TASA_SELECCION 0.8
#define PROB_MUTAR 0.1
#define PUNTO_CORTE 0.5

#define CAPACIDAD 15
#define CANT_CAMIONES 3

void imprimir() {
    cout << "Mejor cromosoma encontrado: " << endl;
    cout << "|";
    cout << "\nCamion: " << endl;
    cout << "Paquetes: " << endl;
    cout << "Carga: " << endl;
    cout << "Capacidad restante:" << endl;
}


vector<int> calcularCarga(const vector<int>& paquetes,
                          const vector<int>& individuo) {
    vector<int> carga(CANT_CAMIONES, 0);
    for (int i = 0; i < individuo.size(); i += 2) {
        // 2 bits del individuo representan el camión asignado:
        int indiceCamion = 2 * individuo[i] + individuo[i+1];
        if (indiceCamion < CANT_CAMIONES) {
            carga[indiceCamion] += paquetes[i/2];
        }
    }
    return carga;
}

bool excedeCarga(const vector<int>& carga) {
    for (int c : carga) {
        if (c > CAPACIDAD) return true;
    }
    return false;
}

bool esAberracion(const vector<int>& paquetes,
                  const vector<int>& individuo) {
    vector<int> carga = calcularCarga(paquetes, individuo);
    return excedeCarga(carga);
}

void mataclon(vector<vector<int>>& poblacion) {
    map<vector<int>, bool> unicos;

    for (const auto& e : poblacion) {
        unicos[e] = true;
    }

    poblacion.clear();

    for (const auto& e : unicos) {
        poblacion.push_back(e.first);
    }
}


vector<vector<int>> generarPoblacion(const vector<int>& paquetes) {
    vector<vector<int>> poblacion;
    srand(time(nullptr));

    while (poblacion.size() < CAPACIDAD) {
        vector<int> individuo;
        for (int i = 0; i < paquetes.size(); i++) {
            individuo.push_back(rand() % 2);
            individuo.push_back(rand() % 2);

        }
        if (!esAberracion(paquetes, individuo)) {
            poblacion.push_back(individuo);
        }
        mataclon(poblacion);
    }
    return poblacion;
}


void regenerarPoblacion(const vector<int>& paquetes,
                        vector<vector<int>>& poblacion) {
    mataclon(poblacion);

    sort(poblacion.begin(), poblacion.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[0] > b[0];
         });

    if (poblacion.size() > TAM_POBLACION) {
        poblacion.erase(poblacion.begin() + TAM_POBLACION, poblacion.end());
    }
}

int calcularFitness(const vector<int>& individuo) {
    int fitness = CANT_CAMIONES;
    map<int, bool> camionesUsados;

    for (int i = 0; i < individuo.size(); i += 2) {
        int indiceCamion = 2 * individuo[i] + individuo[i + 1];
        camionesUsados[indiceCamion] = true;
    }

    return fitness - (int)camionesUsados.size();
}

vector<int> generarFitnessAcumulados(const vector<vector<int>>& poblacion) {
    vector<int> fitnessAcumulados;
    int acumulado = 0;

    for (int i = 0; i < poblacion.size(); i++) {
        acumulado += calcularFitness(poblacion[i]);
        fitnessAcumulados.push_back(acumulado);
    }

    return fitnessAcumulados;
}

vector<vector<int>> generarPadres(const vector<int>& paquetes,
                                  const vector<vector<int>>& poblacion) {
    vector<vector<int>> padres;
    int cantPadres = (int)round(TASA_SELECCION * poblacion.size());
    vector<int> fitnessAcumulados = generarFitnessAcumulados(poblacion);

    for (int i = 0; i < cantPadres; i++) {
        int ticket = rand() % fitnessAcumulados.back();
        int indice = 0;
        while (ticket >= fitnessAcumulados[indice]) {
            indice++;
        }
        padres.push_back(poblacion[indice]);
    }
    return padres;
}


vector<int> generarHijo(const vector<int>& padre,
                        const vector<int>& madre) {
    int puntoCorte = (int)round(PUNTO_CORTE * padre.size());
    vector<int> hijo;
    for (int i = 0; i < puntoCorte; i++)
        hijo.push_back(padre[i]);
    for (int i = puntoCorte; i < madre.size(); i++)
        hijo.push_back(madre[i]);
    return hijo;
}

void mutacion(vector<int>& individuo) {
    if (PROB_MUTAR * 100 > rand() % 100) {
        int gen = rand() % individuo.size();
        individuo[gen] = !individuo[gen];
    }
}


void casamiento(const vector<int>& paquetes,
                vector<vector<int>>& poblacion,
                const vector<vector<int>>& padres) {
    for (int i = 0; i < padres.size(); i++) {
        for (int j = 0; j < padres.size(); j++) {
            if (i != j) {
                vector<int> hijo = generarHijo(padres[i], padres[j]);
                mutacion(hijo);
                if (!esAberracion(paquetes, hijo)) {
                    poblacion.push_back(hijo);
                }
            }
        }
    }
}


int main() {
    const vector<int> paquetes{4, 6, 3, 5, 2, 4};

    vector<vector<int>> poblacion = generarPoblacion(paquetes);
    vector<vector<int>> padres = generarPadres(paquetes, poblacion);
    // casamiento(paquetes, poblacion, padres);
    // regenerarPoblacion(paquetes, poblacion);

    return 0;
}
