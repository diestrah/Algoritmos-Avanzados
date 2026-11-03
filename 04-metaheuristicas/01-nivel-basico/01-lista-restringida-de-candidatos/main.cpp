#include <iostream>
#include <vector>
using namespace std;

#define ALFA 0.5 // ¿Qué sucede si cambias el valor de alfa 0.0?
#define SEMILLA 46523   // Con la misma semilla y el mismo entorno, el resultado se repite.
// Puede variar entre implementaciones de rand().

struct Candidato{
    char nombre;
    int tiempo;
};

struct ResultadoRCL{
    vector<Candidato> rcl;
    int beta; // beta: mejor valor
    int tau; // tau: peor valor
    double umbral;
};


ResultadoRCL construirRCL(const vector<Candidato>& candidatos) {
    ResultadoRCL resultado;

    // Partimos de un tiempo que existe
    resultado.beta = candidatos[0].tiempo;
    resultado.tau = candidatos[0].tiempo;

    for (const Candidato& c : candidatos) {
        // beta será el mejor tiempo
        if (c.tiempo < resultado.beta) {
            resultado.beta = c.tiempo;
        }
        // tau será el peor tiempo
        if (c.tiempo > resultado.tau) {
            resultado.tau = c.tiempo;
        }
    }
    // definimos el umbral para los mejores valores (beta)
    resultado.umbral = resultado.beta + ALFA * (resultado.tau - resultado.beta);

    // Guardamos los candidatos aceptados por el umbral (RCL)
    for (const Candidato& c : candidatos) {
        if (c.tiempo <= resultado.umbral) {
            resultado.rcl.push_back(c);
        }
    }
    return resultado;
}

void imprimir(const ResultadoRCL& resultado, int candidato) {
    cout << "Minimo: " << resultado.beta << "\n";
    cout << "Maximo: " << resultado.tau << "\n";
    cout << "Umbral: " << resultado.umbral << "\n";

    cout << "RCL: ";
    for (Candidato c : resultado.rcl) cout << c.nombre << " ";
    cout << "\n";

    // Elegimos al azar entre los candidatos del RCL
    cout << "Candidato seleccionado: " << resultado.rcl[candidato].nombre << "\n";
    cout << "Tiempo del candidato: " << resultado.rcl[candidato].tiempo << " min\n";
}


int main() {
    vector<Candidato> candidatos = {
        {'A', 25},
        {'B', 10},
        {'C', 40},
        {'D', 15},
        {'E', 30},
        {'F', 20},
    };
    srand(SEMILLA);

    ResultadoRCL resultado = construirRCL(candidatos);
    int indice = rand() % resultado.rcl.size();
    imprimir(resultado, indice);

    return 0;
}
