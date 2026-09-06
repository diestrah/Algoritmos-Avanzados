/*--------------------------------------------------------------------------------------*/
/* Autor : Naim Diestra
/* Fecha : 25/08/2026
/* Descripción:
/* Este programa implementa una función en la que se calcula las combinaciones de un elemento
/* 
/* Ejemplo:
/* Dado un n = 4 y un k = 2, se genera:
/* [1, 2]
/* [1, 3]
/* [1, 4]
/* [2, 3]
/* [2, 4]
/* [3, 4]
/*
/*--------------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

void imprimir(const vector<int>& arr){
	cout << "[";
	for (int i=0; i<arr.size(); i++){
		cout << arr[i];
		if (i < arr.size() - 1){
			cout << ", ";
		}
	}
	cout << "]\n";	
}

// La variable ini indica el elemento inicial del arreglo 
void generarCombinaciones(int n, int k, int ini, vector<int>& combinaciones){

	// Caso base: Si tengo k elementos, se construyó una combinación completa
	if (combinaciones.size() == k){
		imprimir(combinaciones); 
		return;
	}
	
	for (int i = ini; i <= n; i++){
		// Hacer
		combinaciones.push_back(i);
		
		// Recursión: comenzamos desde i + 1 para evitar repetir elementos
		// y así no generar la misma combinación en distinto orden
		generarCombinaciones(n, k, i + 1, combinaciones);
		
		// Deshacer
		combinaciones.pop_back();
	}
}

int main(){
	int n = 4; // rango de elementos: [1, n]
	int k = 2; // cantidad de elementos
	vector<int> combinaciones;
	
	generarCombinaciones(n, k, 1, combinaciones);
	
	return 0;
}

	
