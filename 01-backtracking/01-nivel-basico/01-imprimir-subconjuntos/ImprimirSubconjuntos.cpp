/*-----------------------------------------------------------------*/
/*  Autor : Naim Diestra
/*  Fecha : 24/08/2026
/*-----------------------------------------------------------------*/

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
