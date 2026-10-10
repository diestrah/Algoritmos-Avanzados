/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 26/08/2026
/*-----------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

void imprimir(const string& cadena) {
    cout << cadena << "\n";
}

// Solución iterativa:
void generarCadenasBinariasV1(string& cadena, int bits){
    if (cadena.size() == bits){
        imprimir(cadena);
        return;
    }

    for (int i = 0; i < 2; i++){
		// Hacer
        cadena.push_back('0' + i);
        
        // Recursión
        generarCadenasBinariasV1(cadena, bits);
        
		// Deshacer
		cadena.pop_back();
    }
}

// Solución recursiva
void generarCadenasBinariasV2(string& cadena, int bits){
    if (cadena.size() == bits){
        imprimir(cadena);
        return;
    }

	// CAMINO A: agregamos 0
	
	// Hacer
    cadena.push_back('0' + 0);
    // Seguimos un camino
	generarCadenasBinariasV2(cadena, bits);
    // Deshacer
	cadena.pop_back();
    
    
	// CAMINO B: agregamos 1
    
	// Hacer
	cadena.push_back('0'+ 1);
    // Seguimos otro camino
	generarCadenasBinariasV2(cadena, bits);
    // Deshacer
	cadena.pop_back();
}

int main() {
    string cadena;
    int bits = 3;

    generarCadenasBinariasV1(cadena, bits);
	cout << endl;
	generarCadenasBinariasV2(cadena, bits);
	
    return 0;
}

