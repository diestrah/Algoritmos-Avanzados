/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 26/08/2026
/*-----------------------------------------------------------------*/

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

void SumaObjetivo(const int arr[], int n, int objetivo,
                  int inicio, int suma, vector<int>& actual) {
	// Caso base: encontramos una combinación
	if (suma == objetivo) {
		imprimir(actual);
		return;
	}

	for (int i = inicio; i < n; i++) {
		// Poda: el arreglo está ordenado, ningún elemento posterior cabe
		if (suma + arr[i] > objetivo) break;

		// Hacer
		actual.push_back(arr[i]);                                  
		// Explorar
		SumaObjetivo(arr, n, objetivo, i + 1, suma + arr[i], actual); 
		// Deshacer
		actual.pop_back();                                         
	}
}

int main() {
	int arr[] = {2, 3, 5, 7}; // debe estar ordenado de menor a mayor
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> actual;

	SumaObjetivo(arr, n, 10, 0, 0, actual);
	return 0;
}