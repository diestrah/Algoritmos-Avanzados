/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 27/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

void imprimir(const vector<int>& cambio) {
	cout << "[";
	for (int i = 0; i < cambio.size(); i++) {
		cout << cambio[i];
		if (i < cambio.size() - 1)
			cout << ", ";
	}
	cout << "]\n";
}

void CambioDeMonedas(int monedas[], int n, int monto,
                     vector<int>& cambio, int inicio) {

	// Calulamos suma del cambio
	int suma = 0;
	for (int moneda : cambio) suma += moneda;

	// Caso base: encontramos una solución
	if (suma == monto) {
		imprimir(cambio);
		return;
	}

	// Poda: ya nos pasamos del monto
	if (suma > monto) return;

	// Probamos todas las monedas desde el inicio
	for (int i = inicio; i < n; i++) {

		// Hacer
		cambio.push_back(monedas[i]);

		// Explorar
		CambioDeMonedas(monedas, n, monto, cambio, i);

		// Deshacer
		cambio.pop_back();
	}
}

int main() {

	int monedas[] = {1, 2, 5};
	int n = sizeof(monedas) / sizeof(monedas[0]);
	int monto = 5;
	vector<int> cambio;

	CambioDeMonedas(monedas, n, monto, cambio, 0);

	return 0;
}
