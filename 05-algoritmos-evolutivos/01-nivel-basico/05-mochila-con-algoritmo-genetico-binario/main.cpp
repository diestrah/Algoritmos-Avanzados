#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;

#define TAM_POBLACION 6
#define TASA_SELECCION 0.8
#define GENERACIONES 20
#define PROB_MUTAR 0.1
#define CAPACIDAD 15

struct Objeto{
    int peso;
    int beneficio;
};

int calcularPeso(const vector<int>& individuo,
                 const vector<Objeto>& objetos) {
    int pesoTotal = 0;
    for (int i = 0; i < individuo.size(); i++) {
        if (individuo[i]) {
            pesoTotal += objetos[i].peso;
        }
    }
    return pesoTotal;
}

bool esAberracion(const vector<int>& individuo,
                  const vector<Objeto>& objetos) {
    int pesoTotal = calcularPeso(individuo, objetos);
    return pesoTotal == 0 || pesoTotal > CAPACIDAD;
}

void mataclon(vector<vector<int>>& poblacion) {
    map<vector<int>, bool> individuosUnicos;

    for (auto& individuo : poblacion) {
        individuosUnicos[individuo] = true;
    }

    poblacion.clear();

    for (const auto& elemento : individuosUnicos) {
        poblacion.push_back(elemento.first);
    }
}

vector<vector<int>> generarPoblacion(const vector<Objeto>& objetos) {
    vector<vector<int>> poblacion;
    while (poblacion.size() < TAM_POBLACION) {
        vector<int> individuo(objetos.size());
        for (int j = 0; j < individuo.size(); j++) {
            individuo[j] = rand() % 2;
        }
        if (!esAberracion(individuo, objetos)) {
            poblacion.push_back(individuo);
            mataclon(poblacion); // nos aseguramos de que sean 6 individuos diferentes
        }
    }
    return poblacion;
}

int calcularFitness(const vector<int>& individuo,
                    const vector<Objeto>& objetos) {
    int fitness = 0;
    for (int i = 0; i < individuo.size(); i++) {
        if (individuo[i]) {
            fitness += objetos[i].beneficio;
        }
    }
    return fitness;
}


vector<int> generarFitnessAcumulados(const vector<vector<int>>& poblacion,
                                     const vector<Objeto>& objetos) {
    vector<int> fitnessAcumulados(poblacion.size());
    int acumulado = 0;
    for (int i = 0; i < poblacion.size(); i++) {
        acumulado += calcularFitness(poblacion[i], objetos);
        fitnessAcumulados[i] = acumulado;
    }
    return fitnessAcumulados;
}

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

void mutar(vector<int>& individuo) {
    for (int i = 0; i < individuo.size(); i++) {
        if (rand() % 100 < PROB_MUTAR * 100) {
            individuo[i] = !individuo[i];
        }
    }
}

vector<int> crearHijo(const vector<int>& padre,
                      const vector<int>& madre) {
    int puntoCorte = 1 + rand() % (padre.size() - 1);
    vector<int> hijo(padre.size());

    for (int i = 0; i < puntoCorte; i++)
        hijo[i] = padre[i];
    for (int i = puntoCorte; i < madre.size(); i++)
        hijo[i] = madre[i];

    return hijo;
}

void casamiento(vector<vector<int>>& poblacion,
                const vector<vector<int>>& padres,
                const vector<Objeto>& objetos) {
    for (int i = 0; i < padres.size(); i++) {
        for (int j = 0; j < padres.size(); j++) {
            if (i != j) {
                vector<int> hijo = crearHijo(padres[i], padres[j]);
                mutar(hijo);
                if (!esAberracion(hijo, objetos)) {
                    poblacion.push_back(hijo);
                }
            }
        }
    }
}

void regenerarPoblacion(vector<vector<int>>& poblacion,
                        const vector<Objeto>& objetos) {
    mataclon(poblacion);

    sort(poblacion.begin(), poblacion.end(),
         [&objetos](const vector<int>& a, const vector<int>& b) {
             int fA = calcularFitness(a, objetos);
             int fB = calcularFitness(b, objetos);
             if (fA == fB) {
                 int pA = calcularPeso(a, objetos);
                 int pB = calcularPeso(b, objetos);
                 return pA < pB;
             }
             return fA > fB;
         });

    if (poblacion.size() > TAM_POBLACION) {
        poblacion.erase(poblacion.begin() + TAM_POBLACION, poblacion.end());
    }
}

void imprimirMejorIndividuo(const vector<Objeto>& objetos,
                            const vector<int>& individuo) {
    cout << "\nMejor cromosoma encontrado: ";
    for (int i : individuo) cout << i << " ";
    cout << "\nObjetos seleccionados: ";
    for (int i = 0; i < individuo.size(); i++)
        if (individuo[i]) cout << i + 1 << " ";
    int peso = calcularPeso(individuo, objetos);
    cout << "\nPeso total: " << peso;
    cout << "\nBeneficio total: " << calcularFitness(individuo, objetos);
    cout << "\nCapacidad restante: " << CAPACIDAD - peso << endl;
}


int main() {
    const vector<Objeto> objetos{
        {2, 6}, {3, 8}, {4, 9},
        {5, 12}, {8, 20}, {9, 22}
    };

    srand(time(nullptr));
    vector<vector<int>> poblacion = generarPoblacion(objetos);

    for (int i = 1; i <= GENERACIONES; i++) {
        vector<int> fAcumulados = generarFitnessAcumulados(poblacion, objetos);
        vector<vector<int>> padres = seleccionarPadres(poblacion, fAcumulados);
        casamiento(poblacion, padres, objetos);
        regenerarPoblacion(poblacion, objetos);
        cout << right << "Generacion " << setw(2) << i << " | Mejor beneficio: "
            << calcularFitness(poblacion.front(), objetos) << endl;
    }

    imprimirMejorIndividuo(objetos, poblacion.front());

    return 0;
}
