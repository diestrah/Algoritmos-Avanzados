/*--------------------------------------------------------------------------------------*/
/* Autor : Naim Diestra
/* Fecha : 24/08/2026
/* Descripción:
/* Este programa implementa una función en la que dado un arreglo de elementos, se genera
/* todas las permutaciones posibles del arreglo.
/* Se utiliza backtracking para encontrar la solución.
/* 
/* Ejemplo:
/* Dado un arreglo [1, 2, 3], se generan las permutaciones:
/* [1, 2, 3]
/* [1, 3, 2]
/* [2, 3, 1]
/* [2, 1, 3]
/* [3, 1, 2]
/* [3, 2, 1]
/*
/*--------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;
#include <vector>

void imprimir(const vector<int>& actual){
	cout << "[";
    for (int i = 0; i < actual.size(); i++) {
        cout << actual[i];

        if (i < actual.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

bool estaEnElArray(int num, const vector<int>& actual){
	for (int i=0; i<actual.size(); i++){
		if (num == actual[i]) return true;
	}
	return false;
}


void generarPermutaciones(int arr[], int n, vector<int>& actual){
	// Caso base: se construyó una permutación completa
	if (actual.size() == n){
		imprimir(actual);	
		return;
	}
	
	for (int i=0; i<n; i++){
		// Solo se utilizan elementos que aún no formen parte de la permutación
		if (!estaEnElArray(arr[i], actual)){
			// Hacer
			actual.push_back(arr[i]);
			// Recursión
			generarPermutaciones(arr, n, actual);
			// Deshacer
			actual.pop_back();
		}	
	}
}

int main(){
	int arr[] = {1, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> actual;
	
	generarPermutaciones(arr, n, actual);
	
	return 0;
}
