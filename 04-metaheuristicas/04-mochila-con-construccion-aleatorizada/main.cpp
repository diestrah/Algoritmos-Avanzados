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
    int indice;
    char nombre;
    int peso;
    int valor;
    double valorEntrePeso;
};

struct Mochila{
    vector<Objeto> seleccionados;
    int pesoTotal;
    int valorTotal;
    int capacidadRestante;
};

void calcularRazon(vector<Objeto>& objetos) {
    for (int i = 0; i < objetos.size(); i++) {
        objetos[i].valorEntrePeso = (double)objetos[i].valor / objetos[i].peso;
    }
}

vector<Objeto> generarRCL(const vector<Objeto>& objetos,
                          const vector<bool>& estado, int capacidad) {
    double minimo = INT_MAX;
    double maximo = INT_MIN;
    bool hayCandidatos = false;

    // El criterio para los máximos y minimos será el cociente entre valor y el peso
    for (int i = 0; i < objetos.size(); i++) {
        if (!estado[i] && capacidad >= objetos[i].peso) {
            minimo = min(minimo, objetos[i].valorEntrePeso);
            maximo = max(maximo, objetos[i].valorEntrePeso);
            hayCandidatos = true;
        }
    }

    // Si ningún objeto pendiente cabe, devolvemos una RCL vacía
    if (!hayCandidatos) return {};

    // Razón mínima aceptada: se prefieren valores/peso mayores
    double umbral = maximo - ALFA * (maximo - minimo);
    vector<Objeto> rcl;

    // Construcción de la RCL
    for (int i = 0; i < objetos.size(); i++) {
        if (!estado[i] &&
            objetos[i].peso <= capacidad &&
            objetos[i].valorEntrePeso >= umbral) {
            rcl.push_back(objetos[i]);
        }
    }
    return rcl;
}

Mochila construirMochila(const vector<Objeto>& objetos) {
    // Cada construcción comienza sin objetos seleccionados
    vector<bool> seleccionado(objetos.size(), false);

    // Inicializamos la mochila
    Mochila mochila;
    mochila.capacidadRestante = CAPACIDAD;
    mochila.pesoTotal = 0;
    mochila.valorTotal = 0;

    while (true) {
        vector<Objeto> rcl = generarRCL(objetos, seleccionado, mochila.capacidadRestante);
        if (rcl.empty()) break;

        int indice = rand() % rcl.size();
        Objeto elegido = rcl[indice];

        // Actualizamos los valores de la mochila
        mochila.seleccionados.push_back(elegido);
        mochila.capacidadRestante -= elegido.peso;
        mochila.pesoTotal += elegido.peso;
        mochila.valorTotal += elegido.valor;

        // Actualizamos el estado del objeto
        seleccionado[elegido.indice] = true;
    }

    return mochila;
}

Mochila construirMochilaConMejorValor(const vector<Objeto>& objetos) {
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
        {0, 'A', 30, 120},
        {1, 'B', 10, 60},
        {2, 'C', 20, 100},
        {3, 'D', 25, 90},
        {4, 'E', 15, 45},
        {5, 'F', 8, 16},
    };
    calcularRazon(objetos);
    srand(time(nullptr));
    Mochila mochila = construirMochilaConMejorValor(objetos);
    imprimir(mochila);
    return 0;
}
