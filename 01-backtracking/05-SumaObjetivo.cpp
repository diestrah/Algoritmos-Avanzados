/*--------------------------------------------------------------------------------------*/
/* Autor : Naim Diestra
/* Fecha : 26/08/2026
/* Descripción:
/* Este programa implementa una función en la que dado un arreglo de elementos y un valor
/* se busquen las posibles combinaciones que resulten en una suma. 
/* Cada elemento del arreglo puede seleccionarse como máximo una vez.
/* Se utiliza backtracking en la solución.
/* 
/* Ejemplo:
/* Dado un arreglo [2, 3, 5, 7] y el objetivo de suma = 10, se genera:
/* [2, 3, 5]
/* [3, 7]
/*
/*--------------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;
#define N 4

void imprimir(const vector<int>& suma){
	cout << "[";
	for (int i=0; i< suma.size(); i++){
		cout << suma.at(i);
		if (i < suma.size()-1){
			cout << ", ";
		}
	}
	cout << "]\n";
}

void SumaObjetivo(int arrValores[], int n, int objetivo, vector<int>& arrSuma, int suma){
	if(suma == objetivo) {
		imprimir(arrSuma);
		return;
	}
	
	if (suma > objetivo or n < 0) return;
	
	// Hacer
	arrSuma.push_back(arrValores[n]);
	suma += arrValores[n];
	
	// Probamos un camino
	SumaObjetivo(arrValores, n - 1, objetivo, arrSuma, suma);
	
	// Deshacer
	arrSuma.pop_back();
	suma -= arrValores[n];
	
	// Seguimos otro camino
	SumaObjetivo(arrValores, n - 1, objetivo, arrSuma, suma);
}
	

int main(){
	
	int arrValores[N] = {2, 3, 5, 7};
	int objetivo = 10;
	int suma = 0;
	vector<int> arrSuma;

	SumaObjetivo(arrValores, N-1, objetivo, arrSuma ,suma);	
	
	return 0;
}

