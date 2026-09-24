/*--------------------------------------------------------------------------------------*/
/* Autor : Naim Diestra
/* Fecha : 26/08/2026
/* Descripción:
/* Este programa implementa una función en la que dada una cantidad de bits,
/* se generan todas las combinaciones posibles en binario.
/* Se debe utilizar backtracking para la solución.
/* 
/* Se presentan dos soluciones: una que utiliza un ciclo para explorar las dos 
/* posibilidades y otra que representa explícitamente cada camino de forma recursiva.
/*--------------------------------------------------------------------------------------*/

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

