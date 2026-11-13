#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdlib>
using namespace std;

#define ITERACIONES 1000
#define LIMITE 20
#define ALFA 0.3

// Luego de eliminar las tarifas anteriores, la posición 0
// corresponde siempre a la ciudad actual
#define TARIFA_ACTUAL 0

struct Motorizado{
    int numero;
    vector<int> tarifas;
};

struct Envio{
    char ciudad;
    int numeroMotorizado;
    int costoEnvio;
};

struct Asignacion{
    vector<Envio> envios;
    int costoTotal;
};

bool menorCosto(const Motorizado& a, const Motorizado& b) {
    return a.tarifas[TARIFA_ACTUAL] < b.tarifas[TARIFA_ACTUAL];
}

int calcularFactibles(const vector<Motorizado>& pendientes, int costoCiudad) {
    int cant = 0;
    for (const Motorizado& m : pendientes) {
        int costoTotal = m.tarifas[TARIFA_ACTUAL] + costoCiudad;
        if (costoTotal > LIMITE) break;
        cant++;
    }
    return cant;
}

int calcularCandidatosRCL(const vector<Motorizado>& motorizados,
                          double umbral, int cantidadFactibles) {
    int cant = 0;
    while (cant < cantidadFactibles &&
        motorizados[cant].tarifas[TARIFA_ACTUAL] <= umbral) {
        cant++;
    }

    return cant;
}

void removerTarifas(vector<Motorizado>& motorizados) {
    for (Motorizado& m : motorizados) {
        m.tarifas.erase(m.tarifas.begin());
    }
}

Asignacion construirAsignacion(const vector<Motorizado>& motorizados,
                               const vector<int>& costosTransporte) {
    Asignacion asignacion{{}, 0};

    // Le asignamos una copia a pendientes
    vector<Motorizado> pendientes = motorizados;
    sort(pendientes.begin(), pendientes.end(), menorCosto);

    // Atendemos las ciudades en el orden en que se reciben
    for (int ciudad = 0; ciudad < costosTransporte.size(); ciudad++) {

        // Verificamos que todavia hayan motorizados y ordenamos
        if (pendientes.empty()) break;
        sort(pendientes.begin(), pendientes.end(), menorCosto);

        // Verificamos que hayan candidatos factibles
        int cantidadFactibles = calcularFactibles(pendientes, costosTransporte[ciudad]);
        if (cantidadFactibles == 0) break;

        // Calculamos tau, beta y umbral
        int beta = pendientes.front().tarifas[TARIFA_ACTUAL];
        int tau = pendientes[cantidadFactibles - 1].tarifas[TARIFA_ACTUAL];
        double umbral = beta + ALFA * (tau - beta);

        // Seleccionamos un candidato valido
        int cantidadRCL = calcularCandidatosRCL(pendientes, umbral, cantidadFactibles);
        int posicion = rand() % cantidadRCL;
        const Motorizado& elegido = pendientes[posicion];

        // Completamos la informacion del envio
        Envio envio;
        envio.ciudad = 'A' + ciudad;
        envio.numeroMotorizado = elegido.numero;
        envio.costoEnvio = costosTransporte[ciudad] + elegido.tarifas[TARIFA_ACTUAL];

        // Lo agregamos a la asignación
        asignacion.envios.push_back(envio);
        asignacion.costoTotal += envio.costoEnvio;

        // Eliminamos tarifa y motorizado
        pendientes.erase(pendientes.begin() + posicion);
        removerTarifas(pendientes);
    }

    return asignacion;
}

Asignacion buscarMejorAsignacion(const vector<Motorizado>& motorizados,
                                 const vector<int>& costosTransporte) {
    Asignacion mejorAsignacion{{}, INT_MAX};
    srand(time(nullptr));

    for (int iteracion = 0; iteracion < ITERACIONES; iteracion++) {
        Asignacion asignacion = construirAsignacion(motorizados, costosTransporte);
        bool esAsignacionCompleta = asignacion.envios.size() == costosTransporte.size();

        // Solo compararemos las asignaciones completas
        if (esAsignacionCompleta &&
            asignacion.costoTotal < mejorAsignacion.costoTotal) {
            mejorAsignacion = asignacion;
        }
    }

    return mejorAsignacion;
}

void imprimir(const Asignacion& asignacion) {
    cout << "Limite por envio: " << LIMITE << " soles\n";
    cout << "Alfa: " << ALFA << "\n";
    cout << "Iteraciones: " << ITERACIONES << "\n";

    for (const Envio& envio : asignacion.envios) {
        cout << "\nCiudad " << envio.ciudad << ":\n";
        cout << "Motorizado: " << envio.numeroMotorizado << "\n";
        cout << "Costo del envio: " << envio.costoEnvio << " soles\n";
    }

    cout << "\nCosto total: " << asignacion.costoTotal << " soles\n";
}

int main() {
    const vector<Motorizado> motorizados = {
        {1, {3, 4, 5, 6}},
        {2, {5, 2, 3, 4}},
        {3, {7, 5, 4, 2}},
        {4, {8, 7, 5, 1}},
        {5, {4, 3, 7, 5}}
    };

    const vector<int> costosTransporte = {16, 15, 12, 18};

    Asignacion mejorAsignacion = buscarMejorAsignacion(motorizados, costosTransporte);

    if (mejorAsignacion.envios.size() == costosTransporte.size()) {
        imprimir(mejorAsignacion);
    }
    else {
        cout << "No se encontro una asignacion completa.\n";
    }

    return 0;
}
