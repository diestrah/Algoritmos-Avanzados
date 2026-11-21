#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
using namespace std;

#define TAM_POBLACION 6
#define GENERACIONES 100
#define TASA_SELECCION 0.8
#define PROB_MUTACION 0.1
#define PRESUPUESTO 300

struct Activo{
    int precioActual;
    int precioOptimista;
    int precioPesimista;
};

Activo calcularTotales(const vector<Activo>& activos,
                       const vector<int>& individuo) {
    Activo total{0, 0, 0};
    for (int i = 0; i < individuo.size(); i++) {
        if (individuo[i]) {
            total.precioActual += activos[i].precioActual;
            total.precioOptimista += activos[i].precioOptimista;
            total.precioPesimista += activos[i].precioPesimista;
        }
    }
    return total;
}

bool esAberracion(const vector<Activo>& activos,
                  const vector<int>& individuo) {
    int cant = 0;
    for (int i = 0; i < individuo.size(); i++) cant += individuo[i];
    Activo total = calcularTotales(activos, individuo);
    return cant == 0 || total.precioActual > PRESUPUESTO;
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

int calcularFitness(const vector<Activo>& activos,
                    const vector<int>& individuo) {
    int fitness = 0;
    for (int i = 0; i < individuo.size(); i++) {
        if (individuo[i]) {
            int ganancia =
                activos[i].precioOptimista - activos[i].precioActual;
            int perdida =
                activos[i].precioActual - activos[i].precioPesimista;
            fitness += ganancia - perdida;
        }
    }
    return fitness;
}

vector<vector<int>> generarPoblacion(const vector<Activo>& activos) {
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

vector<int> generarFitnessAcumulados(const vector<Activo>& activos,
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

void casamiento(const vector<Activo>& activos,
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


void regenerarPoblacion(const vector<Activo>& activos,
                        vector<vector<int>>& poblacion) {
    mataclon(poblacion);

    sort(poblacion.begin(), poblacion.end(),
         [&activos](const vector<int>& a, const vector<int>& b) {
             int fA = calcularFitness(activos, a);
             int fB = calcularFitness(activos, b);
             if (fA != fB) {
                 return fA > fB;
             }
             return calcularTotales(activos, a).precioActual <
                 calcularTotales(activos, b).precioActual;
         });

    if (poblacion.size() > TAM_POBLACION) {
        poblacion.erase(poblacion.begin() + TAM_POBLACION, poblacion.end());
    }
}

void imprimirPortafolio(const vector<Activo>& activos,
                        const vector<int>& individuo) {
    Activo totales = calcularTotales(activos, individuo);
    cout << "Mejor cromosoma encontrado: ";
    for (int gen : individuo) cout << gen << " ";
    cout << "\nActivos seleccionados: ";
    for (int i = 0; i < individuo.size(); i++)
        if (individuo[i]) cout << i + 1 << " ";

    cout << "\n\nPresupuesto: " << PRESUPUESTO << endl;
    cout << "Costo actual: " << totales.precioActual << endl;
    cout << "Valor optimista: " << totales.precioOptimista << endl;
    cout << "Valor pesimista: " << totales.precioPesimista << endl;
    cout << "Ganancia potencial: " << totales.precioOptimista - totales.precioActual << endl;
    cout << "Perdida potencial: " << totales.precioActual - totales.precioPesimista << endl;
    cout << "Fitness: " << calcularFitness(activos, individuo) << endl;
    cout << "Presupuesto restante: " << PRESUPUESTO - totales.precioActual << endl;
}

void seleccionarPortafolio(const vector<Activo>& activos) {
    srand(time(nullptr));
    vector<vector<int>> poblacion = generarPoblacion(activos);

    for (int i = 0; i < GENERACIONES; i++) {
        vector<int> fitnessAcumulados = generarFitnessAcumulados(activos, poblacion);
        vector<vector<int>> padres = seleccionarPadres(poblacion, fitnessAcumulados);
        casamiento(activos, poblacion, padres);
        regenerarPoblacion(activos, poblacion);
    }

    imprimirPortafolio(activos, poblacion.front());
}


int main() {
    const vector<Activo> activos{
        {100, 150, 80},
        {120, 180, 100},
        {80, 110, 70},
        {150, 230, 120},
        {90, 140, 75},
        {110, 160, 90},
    };

    seleccionarPortafolio(activos);

    return 0;
}
