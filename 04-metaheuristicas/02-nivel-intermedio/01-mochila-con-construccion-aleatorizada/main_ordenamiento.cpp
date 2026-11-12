#include <iostream>
#include <vector>
#include <algorithm>    // min, max
#include <climits>      // INT_MIN, INT_MAX
#include <ctime>        // time
#include <cstdlib>      // rand y srand
using namespace std;

#define ALFA 0.3
#define CAPACIDAD 50
#define ITERACIONES 1000

struct Objeto{
    char nombre;
    int peso;
    int valor;
    double valorPorPeso;
};

struct Mochila{
    vector<Objeto> seleccionados;
    int pesoTotal;
    int valorTotal;
    int capacidadRestante;
};

bool mayorValorEntrePeso(const Objeto& a, const Objeto& b) {
    return a.valorPorPeso > b.valorPorPeso;
}

void calcularValorEntrePeso(vector<Objeto>& objetos) {
    for (int i = 0; i < objetos.size(); i++) {
        objetos[i].valorPorPeso = (double)objetos[i].valor / objetos[i].peso;
    }
}

int contarCandidatosRCL(const vector<Objeto>& pendientes, double umbral) {
    int cantidadRCL = 0;
    while (cantidadRCL < pendientes.size() &&
        pendientes[cantidadRCL].valorPorPeso >= umbral) {
        cantidadRCL++;
    }
    return cantidadRCL;
}

void eliminarObjetosQueNoCaben(vector<Objeto>& pendientes,
                               int capacidadRestante) {
    for (int i = 0; i < pendientes.size();) {
        if (pendientes[i].peso > capacidadRestante) {
            pendientes.erase(pendientes.begin() + i);
        }
        else {
            i++;
        }
    }
}

Mochila construirMochila(const vector<Objeto>& objetos) {
    // La copia conserva el orden del vector original
    vector<Objeto> pendientes = objetos;

    // Inicializamos la mochila
    Mochila mochila{{}, 0, 0, CAPACIDAD};

    while (!pendientes.empty()) {
        eliminarObjetosQueNoCaben(pendientes, mochila.capacidadRestante);
        if (pendientes.empty()) break;

        double beta = pendientes.front().valorPorPeso; // mejor valor
        double tau = pendientes.back().valorPorPeso; // peor valor
        double umbral = beta + ALFA * (tau - beta);

        // La RCL ocupa las primeras posiciones del vector
        int cantidadRCL = contarCandidatosRCL(pendientes, umbral);
        int posicion = rand() % cantidadRCL;
        Objeto& objetoElegido = pendientes[posicion];


        // Actualizamos los valores de la mochila
        mochila.seleccionados.push_back(objetoElegido);
        mochila.capacidadRestante -= objetoElegido.peso;
        mochila.pesoTotal += objetoElegido.peso;
        mochila.valorTotal += objetoElegido.valor;

        // Actualizamos el estado del objeto
        pendientes.erase(pendientes.begin() + posicion);
    }

    return mochila;
}

Mochila buscarMejorMochila(const vector<Objeto>& objetos) {
    Mochila mejorMochila;
    mejorMochila.valorTotal = INT_MIN;

    for (int i = 0; i < ITERACIONES; i++) {
        Mochila mochila = construirMochila(objetos);
        // Nos quedamos con la mochila con el mayor valor
        if (mejorMochila.valorTotal < mochila.valorTotal) {
            mejorMochila = mochila;
        }
    }

    return mejorMochila;
}

void imprimir(const Mochila& mochila) {
    cout << "Capacidad de la mochila: " << CAPACIDAD << endl;
    cout << "Alfa: " << ALFA << endl;
    cout << "Iteraciones: " << ITERACIONES << endl;
    cout << "\nObjetos seleccionados: [";
    for (int i = 0; i < mochila.seleccionados.size(); i++) {
        if (i != 0) cout << ", ";
        cout << mochila.seleccionados[i].nombre;
    }
    cout << "]\nPeso total: " << mochila.pesoTotal << endl;
    cout << "Valor total: " << mochila.valorTotal << endl;
    cout << "Capacidad restante: " << mochila.capacidadRestante << endl;
}

int main() {
    vector<Objeto> objetos = {
        {'A', 30, 120},
        {'B', 10, 60},
        {'C', 20, 100},
        {'D', 25, 90},
        {'E', 15, 45},
        {'F', 8, 16},
    };

    srand(time(nullptr));

    // Ordenamos los objetos por mayor Valor/Peso
    calcularValorEntrePeso(objetos);
    sort(objetos.begin(), objetos.end(), mayorValorEntrePeso);

    Mochila mochila = buscarMejorMochila(objetos);
    imprimir(mochila);

    return 0;
}
