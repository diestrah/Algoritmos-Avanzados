#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Objeto{
    char nombre;
    int peso;
    int valor;
};

bool compararObjetos(const Objeto& a, const Objeto& b) {
    // Calculamos la razón: valor/peso
    double izquierda = (double)a.valor / a.peso;
    double derecha = (double)b.valor / b.peso;
    if (izquierda != derecha) return izquierda > derecha;

    // Desempate: retornamos el menor identificador primero
    return a.nombre < b.nombre;
}

void llenarMochila(const Objeto* objetos, int n, vector<Objeto>& mochila, int& capacidad) {
    int indice = 0;
    while (capacidad > 0 && indice < n) {
        if (objetos[indice].peso <= capacidad) {
            capacidad -= objetos[indice].peso;
            mochila.push_back(objetos[indice]);
        }
        indice++;
    }
}

void imprimir(const vector<Objeto>& mochila, int capacidad) {
    int pesoTotal = 0, valorTotal = 0;
    bool noInicio = false;
    cout << "Objetos seleccionados: [";
    for (Objeto objeto : mochila) {
        pesoTotal += objeto.peso;
        valorTotal += objeto.valor;
        if (noInicio) cout << ", ";
        cout << objeto.nombre;
        noInicio = true;
    }
    cout << "]\nPeso total: " << pesoTotal << endl;
    cout << "Valor total: " << valorTotal << endl;
    cout << "Capacidad restante: " << capacidad << endl;
}


int main() {
    Objeto objetos[] = {
        {'A', 30, 120},
        {'B', 10, 60},
        {'C', 20, 100},
        {'D', 25, 90},
        {'E', 15, 45},
        {'F', 8, 16},
    };
    int n = sizeof(objetos) / sizeof(objetos[0]);
    int capacidad = 50;
    vector<Objeto> mochila;

    sort(objetos, objetos + n, compararObjetos); // Ordenamos por mayor cociente valor/peso
    llenarMochila(objetos, n, mochila, capacidad);
    imprimir(mochila, capacidad);

    return 0;
}
