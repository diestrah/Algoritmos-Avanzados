#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdlib>
using namespace std;

#define PRESUPUESTO 400
#define ALFA 1.0
#define ITERACIONES 1000

struct Proyecto{
    int costo;
    int ganancia;
    vector<int> predecesores;
    double gananciaPorCosto;
};

struct Seleccion{
    vector<int> proyectosSeleccionados;
    int costoTotal;
    int gananciaTotal;
    int presupuestoRestante;
};


void calcularGananciaPorCosto(vector<Proyecto>& proyectos) {
    for (Proyecto& p : proyectos) {
        p.gananciaPorCosto = (double)p.ganancia / p.costo;
    }
}

vector<int> construirRCL(const vector<Proyecto>& proyectos,
                         const vector<bool>& estados,
                         const vector<int> predecesores) {
    int minimo = INT_MAX;
    int maximo = INT_MIN;
    for (int i = 0; i < proyectos.size(); i++) {
        if (!estados[i])
    }
    vector<int> rcl;
    return rcl;
}

Seleccion generarSeleccion(const vector<Proyecto>& proyectos) {
    vector<bool> estados(proyectos.size(), false);
    Seleccion seleccion{{}, 0, 0, PRESUPUESTO};
    for (int i = 0; i < proyectos.size(); i++) {
    }
    return seleccion;
}

Seleccion mejorSeleccionDeProyectos(const vector<Proyecto>& proyectos) {
    Seleccion mejorSeleccion;
    mejorSeleccion.gananciaTotal = INT_MIN;

    for (int i = 0; i < ITERACIONES; i++) {
        Seleccion seleccion = generarSeleccion(proyectos);
        if (mejorSeleccion.gananciaTotal < seleccion.gananciaTotal) {
            mejorSeleccion = seleccion;
        }
    }
    return mejorSeleccion;
}

void imprimir(const Seleccion& seleccion) {
    cout << "Presupuesto inicial: " << PRESUPUESTO << endl;
    cout << "Alfa: " << ALFA << endl;
    cout << "Iteraciones: " << ITERACIONES << endl;

    cout << "\nProyectos seleccionados: [";
    for (int i = 0; i < seleccion.proyectosSeleccionados.size(); i++) {
        if (i != 0) cout << ", ";
        cout << seleccion.proyectosSeleccionados[i];
    }
    cout << "]\nCosto total: " << seleccion.costoTotal << endl;
    cout << "Ganancia total: " << seleccion.gananciaTotal << endl;
    cout << "Presupuesto restante: " << seleccion.presupuestoRestante << endl;
}


int main() {
    vector<Proyecto> proyectos{
        {100, 200},
        {50, 300, {1}},
        {150, 300, {1}},
        {50, 400},
        {50, 200, {4}},
        {150, 800, {2, 4}},
        {100, 250}
    };
    calcularGananciaPorCosto(proyectos);
    srand(time(nullptr));

    return 0;
}
