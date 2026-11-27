#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

#define TAM_POBLACION 4
#define GENERACIONES 100
#define TASA_SELECCION 0.8
#define PROB_MUTACION 0.1

struct Tarea{
    int horaInicio;
    int horaFin;
    int beneficio;
};

bool esAberracion(const vector<Tarea>& activos,
                  const vector<int>& individuo) {
    int solapamientos = 0;
    for (int i = 0; i < individuo.size(); i++) {
        for (int j = 0; j < individuo.size(); j++) {
            if (i != j && individuo[i] && individuo[j]) {
                if (activos[i].horaInicio < activos[j].horaInicio &&
                    activos[j].horaInicio < activos[i].horaFin) {
                    solapamientos++;
                }
            }
        }
    }
    return solapamientos != 0;
}

void mataclon(vector<vector<int>>& poblacion) {
    map<vector<int>, bool> existe;
    for (const auto& individuo : poblacion) {
        existe[individuo] = true;
    }
    poblacion.clear();

    for (const auto& elemento : existe) {
        poblacion.push_back(elemento.first);
    }
}

int calcularFitness(const vector<Tarea>& tareas,
                    const vector<int>& individuo) {
    int fitness = 0;
    for (int i = 0; i < individuo.size(); i++) {
        fitness += tareas[i].beneficio * individuo[i];
    }
    return fitness;
}

vector<vector<int>> generarPoblacion(const vector<Tarea>& activos) {
    vector<vector<int>> poblacion;

    while (poblacion.size() < TAM_POBLACION) {
        vector<int> individuo(activos.size());

        for (int i = 0; i < activos.size(); i++) {
            individuo[i] = rand() % 2;
        }

        if (!esAberracion(activos, individuo)) {
            poblacion.push_back(individuo);
            mataclon(poblacion);
        }
    }

    return poblacion;
}

vector<int> generarFitnessAcumulados(const vector<Tarea>& activos,
                                     const vector<vector<int>>& poblacion) {
    vector<int> fitnessAcumulados(poblacion.size());
    int acumulado = 0;
    for (int i = 0; i < poblacion.size(); i++) {
        acumulado += calcularFitness(activos, poblacion[i]);
        fitnessAcumulados[i] = acumulado;
    }
    return fitnessAcumulados;
}

// es seleccion por ruleta
vector<vector<int>> seleccionarPadres(const vector<vector<int>>& poblacion,
                                      const vector<int>& fitnessAcumulados) {
    vector<vector<int>> padres;
    int cantPadres = (int)round(poblacion.size() * TASA_SELECCION);

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
    vector<int> hijo(padre.size());
    for (int i = 0; i < padre.size(); i++) {
        hijo[i] = rand() % 2 ? padre[i] : madre[i];
    }
    return hijo;
}


void mutar(vector<int>& individuo) {
    if (rand() % 100 < PROB_MUTACION * 100) {
        // Seleccionamos un gen al azar
        int indiceGen = rand() % individuo.size();
        individuo[indiceGen] = !individuo[indiceGen];
    }
}

void casamiento(const vector<Tarea>& activos,
                vector<vector<int>>& poblacion,
                const vector<vector<int>>& padres) {
    for (int i = 0; i < padres.size(); i++) {
        for (int j = 0; j < padres.size(); j++) {
            if (i != j) {
                vector<int> hijo = generarHijo(padres[i], padres[j]);
                mutar(hijo);
                if (!esAberracion(activos, hijo)) {
                    poblacion.push_back(hijo);
                }
            }
        }
    }
}

void regenerarPoblacion(const vector<Tarea>& activos,
                        vector<vector<int>>& poblacion) {
    mataclon(poblacion);

    sort(poblacion.begin(), poblacion.end(),
         [&activos](const vector<int>& a, const vector<int>& b) {
             int fA = calcularFitness(activos, a);
             int fB = calcularFitness(activos, b);
             return fA > fB;
         });

    if (poblacion.size() > TAM_POBLACION) {
        poblacion.erase(poblacion.begin() + TAM_POBLACION, poblacion.end());
    }
}

void imprimirPortafolio(const vector<Tarea>& activos,
                        const vector<int>& individuo) {
    cout << "Mejor cromosoma encontrado: ";
    for (int gen : individuo) cout << gen << " ";
    cout << "\nActivos seleccionados: ";
    for (int i = 0; i < individuo.size(); i++)
        if (individuo[i]) cout << i + 1 << " ";
    cout << "Fitness: " << calcularFitness(activos, individuo) << endl;
}

void seleccionarPortafolio(const vector<Tarea>& tareas) {
    srand(time(nullptr));
    vector<vector<int>> poblacion = generarPoblacion(tareas);

    for (int i = 0; i < GENERACIONES; i++) {
        vector<int> fitnessAcumulados = generarFitnessAcumulados(tareas, poblacion);
        vector<vector<int>> padres = seleccionarPadres(poblacion, fitnessAcumulados);
        casamiento(tareas, poblacion, padres);
        regenerarPoblacion(tareas, poblacion);
    }

    imprimirPortafolio(tareas, poblacion.front());
}


int main() {
    const vector<Tarea> tareas{
        {0, 3, 35},
        {1, 4, 50},
        {3, 6, 40},
        {2, 5, 45},
        {5, 8, 60},
        {6, 9, 70},
        {7, 10, 55},
        {9, 12, 30},
    };

    seleccionarPortafolio(tareas);

    return 0;
}
