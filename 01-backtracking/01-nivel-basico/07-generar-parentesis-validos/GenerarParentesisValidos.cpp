/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 31/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

// Solución con iteración (V1)
void GenerarParentesisValidosV1(string& cadena, int numParentesis, int cantAbiertos, int cantCerrados){
	if (cadena.size() == numParentesis * 2 and cantAbiertos == cantCerrados) {
		cout << cadena << endl;
		return;
	}
	if (cantAbiertos > numParentesis or cantCerrados > cantAbiertos) return;
	
	for (int i = 0; i < 2; i++){
		if (i == 0) {
			cadena.push_back('(');
			GenerarParentesisValidosV1(cadena, numParentesis, cantAbiertos + 1, cantCerrados);
			cadena.pop_back();
		}
		if (i == 1) {
			cadena.push_back(')');
			GenerarParentesisValidosV1(cadena, numParentesis, cantAbiertos, cantCerrados + 1);
			cadena.pop_back();
		}
	}

}
	

// Solución netamente recursiva
void GenerarParentesisValidos(string& cadena, int numParentesis, int abiertos, int cantCerrados){
	// Caso base
	if (abiertos == cantCerrados and cadena.size() == numParentesis * 2) {
		cout << cadena << endl;
		return;
	}
	// Condiciones de poda
	if (abiertos > numParentesis or
		cantCerrados > numParentesis or 
		cantCerrados > abiertos) return;
	
	if (abiertos < numParentesis) {
		cadena.push_back('('); // hacer
		GenerarParentesisValidos(cadena, numParentesis, abiertos + 1, cantCerrados);
		cadena.pop_back(); // deshacer
	}
	if (cantCerrados < abiertos) {
		cadena.push_back(')'); // hacer
		GenerarParentesisValidos(cadena, numParentesis, abiertos, cantCerrados + 1);
		cadena.pop_back(); // deshacer
	}
}

int main() {
	string cadena;
	int cantAbiertos = 0;
	int cantCerrados = 0;
	int numParentesis = 3;
	
	GenerarParentesisValidosV1(cadena, numParentesis, cantAbiertos, cantCerrados);	
	GenerarParentesisValidos(cadena, numParentesis, cantAbiertos, cantCerrados);
	return 0;
}
