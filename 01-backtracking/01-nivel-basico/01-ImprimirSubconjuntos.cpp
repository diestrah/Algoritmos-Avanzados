/*--------------------------------------------------------------------------------------*/
/* Autor : Naim Diestra
/* Fecha : 24/08/2026
/* Descripción:
/* Este programa implementa una función en la que dado un arreglo de elementos, se genera
/* todos los subconjuntos posibles.
/* Se utiliza backtracking para encontrar la solución.
/* 
/* Ejemplo:
/* Dado un arreglo [1, 2, 3], se generan los subconjuntos:
/* [1, 2, 3]
/* [1, 2]
/* [1, 3]
/* [1]
/* [2, 3]
/* [2]
/* [3]
/* []
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

void generarSubconjuntos(int arr[], int n, int indice, vector<int>& actual){
	if (n == indice) {
		imprimir(actual);
		return;
	}
	// Hacer
	actual.push_back(arr[indice]);
	// Seguimos un camino
	generarSubconjuntos(arr, n, indice + 1, actual);
	// Deshacer
	actual.pop_back();
	// Seguimos otro camino
	generarSubconjuntos(arr, n, indice + 1, actual);
}

int main(){
	int arr[3] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> actual;
	
	generarSubconjuntos(arr, n, 0, actual);	
	return 0;
}
