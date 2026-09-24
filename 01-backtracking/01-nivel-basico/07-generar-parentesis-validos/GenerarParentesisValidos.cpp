/*--------------------------------------------------------------------------------------*/
/* Autor : Naim Diestra
/* Fecha : 31/08/2026
/* Descripción:
/* Este programa implementa una función que, dada la cantidad de parentesis, 
/* genera todas combinaciones válidas de paréntesis.
/* Se presentan dos soluciones: una con iteración y otra netamente recursiva.
/*--------------------------------------------------------------------------------------*/

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
void GenerarParentesisValidosV2(string& cadena, int numParentesis, int cantAbiertos, int cantCerrados){
	// Caso base
	if (cantAbiertos == cantCerrados and cadena.size() == numParentesis * 2) {
		cout << cadena << endl;
		return;
	}
	// Condiciones de poda
	if (cantAbiertos > numParentesis or 
		cantCerrados > numParentesis or 
		cantCerrados > cantAbiertos) return;
	
	if (cantAbiertos < numParentesis) {
		cadena.push_back('('); // hacer
		GenerarParentesisValidosV2(cadena, numParentesis, cantAbiertos + 1, cantCerrados);
		cadena.pop_back(); // deshacer
	}
	if (cantCerrados < cantAbiertos) {
		cadena.push_back(')'); // hacer
		GenerarParentesisValidosV2(cadena, numParentesis, cantAbiertos, cantCerrados + 1);
		cadena.pop_back(); // deshacer
	}
}

int main() {
	string cadena;
	int cantAbiertos = 0;
	int cantCerrados = 0;
	int numParentesis = 3;
	
	GenerarParentesisValidosV1(cadena, numParentesis, cantAbiertos, cantCerrados);	
	GenerarParentesisValidosV2(cadena, numParentesis, cantAbiertos, cantCerrados);	
	return 0;
}
