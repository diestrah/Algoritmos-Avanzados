#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

#define INDIVIDUOS 5
#define CANT_GENES 6
#define TASA_SELECCION 0.6
#define TAMANO_TORNEO 3


/*----------------------------------------------------------------------------*/
/* Inicio seccion reciclada del ejercicio anterior
/*----------------------------------------------------------------------------*/

vector<vector<int>> generarPoblacion() {
    vector<vector<int>> poblacion;
    srand(time(nullptr));

    for (int i = 0; i < INDIVIDUOS; i++) {
        vector<int> individuo(CANT_GENES);
        for (int j = 0; j < CANT_GENES; j++) {
            individuo[j] = rand() % 2;
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
    for (int i = 0; i < poblacion.size(); i++) {
        cout << "Individuo " << i + 1 << ": ";
        imprimirIndividuo(poblacion[i]);
        int fitness = calcularFitness(poblacion[i]);
        cout << "| Fitness: " << fitness << endl;
    }
}

/*----------------------------------------------------------------------------*/
/* Fin seccion reciclada del ejercicio anterior
/*----------------------------------------------------------------------------*/

vector<int> calcularSupervivencia(const vector<vector<int>>& poblacion) {
    // Calculamos los acumulados y los almacenaremos en supervivencia
    vector<int> supervivencia;
    int acumulado = 0;

    // supervivencia[i] contiene la suma de fitness desde el individuo 0 hasta i
    for (int i = 0; i < poblacion.size(); i++) {
        acumulado += calcularFitness(poblacion[i]);
        supervivencia.push_back(acumulado);
    }
    // El ultimo acumulado es igual al fitness total
    return supervivencia;
}

vector<vector<int>> seleccionPorRuleta(const vector<vector<int>>& poblacion) {
    vector<vector<int>> padres;
    vector<int> supervivencia = calcularSupervivencia(poblacion);

    // supervivencia.back() contiene el fitness total
    int sumaFitness = supervivencia.back();

    // TASA_SELECCION indica la proporcion que utilizaremos como padres
    int cantidadPadres = (int)round(poblacion.size() * TASA_SELECCION);

    // Generamos la poblacion de padres
    for (int i = 0; i < cantidadPadres; i++) {
        int indice;

        if (sumaFitness == 0) {
            // Si todos tienen fitness 0, elegimos al azar
            indice = rand() % poblacion.size();
        }
        else {
            int ticket = rand() % sumaFitness;
            indice = 0;

            // Buscamos hasta encontrar el primer cuantil mayor al ticket
            while (ticket >= supervivencia[indice]) {
                /* El indice avanzará hasta encontrar el primer acumulado mayor al ticket
                 * Ejemplo de representacion grafica de como funciona la eleccion del padre:

                 *  Individuo  fitness  Acumulado  Probabilidad  Tickets
                 *      0         3         3          3/9       0, 1, 2
                 *      1         2         5          5/9       3, 4
                 *      2         4         9          9/9       5, 6, 7, 8
                 */

                indice++;
            }
        }

        // Agregamos el individuo elegido como padre
        padres.push_back(poblacion[indice]);
    }

    return padres;
}

vector<vector<int>> seleccionPorTorneo(const vector<vector<int>>& poblacion) {
    vector<vector<int>> padres;

    // TASA_SELECCION indica qué cantidad utilizaremos como padres
    int cantidadPadres = (int)round(poblacion.size() * TASA_SELECCION);

    // Generamos la poblacion de padres
    for (int i = 0; i < cantidadPadres; i++) {
        int indiceGanador = -1;
        int mejorFitness = -1;

        for (int j = 0; j < TAMANO_TORNEO; j++) {
            // Seleccionamos un participante aleatoriamente y calculamos su fitness
            int indiceParticipante = rand() % poblacion.size();
            int fitness = calcularFitness(poblacion[indiceParticipante]);

            // Lo comparamos con el mejor fitness del torneo
            if (fitness > mejorFitness) {
                mejorFitness = fitness;
                indiceGanador = indiceParticipante;
            }
        }

        // Agregamos al individuo ganador del torneo como padre
        padres.push_back(poblacion[indiceGanador]);
    }

    return padres;
}

int main() {
    vector<vector<int>> poblacion = generarPoblacion();
    cout << "Poblacion inicial:\n" << endl;
    imprimirPoblacion(poblacion);

    vector<vector<int>> ruleta = seleccionPorRuleta(poblacion);
    cout << "\nSeleccion por ruleta:\n" << endl;
    imprimirPoblacion(ruleta);

    vector<vector<int>> torneo = seleccionPorTorneo(poblacion);
    cout << "\nSeleccion por torneo\n" << endl;
    imprimirPoblacion(torneo);

    return 0;
}
