/*----------------------------------------------------------------------------------*/
/* Autor: Naim Diestra
/* Fecha: 04/09/2026
/* Descripcion:
/* Este programa implementa el problema de las N-Reinas utilizando backtracking.
/* Se busca colocar N reinas en un tablero de N x N de manera que ninguna reina
/* pueda atacar a otra.
/*----------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;
#define N 4

bool recorrerDiagonalIzquierda(const vector<vector<int>>& tablero, int fila, int col) {
	if (fila < 0 || col < 0) {
		return true;
	}
	
	if (tablero[fila][col] == 1) {
		return false;
	}
	 
	return recorrerDiagonalIzquierda(tablero, fila - 1, col - 1);
}

bool recorrerArriba(const vector<vector<int>>& tablero, int fila, int col) {
	if (fila < 0) {
		return true;
	}
	
	if (tablero[fila][col] == 1) {
		return false;	
	}
	
	return recorrerArriba(tablero, fila - 1, col);
}

bool recorrerDiagonalDerecha(const vector<vector<int>>& tablero, int fila, int col) {
	if (fila < 0 || col >= tablero[0].size()) {
		return true;
	}
	
	if (tablero[fila][col] == 1) {
		return false;
	} 
	
	return recorrerDiagonalDerecha(tablero, fila - 1, col + 1);
}

bool verificarValidez(const vector<vector<int>>& tablero, int fila, int col){	
	return recorrerDiagonalIzquierda(tablero, fila - 1, col - 1) &&  
		   recorrerArriba(tablero, fila - 1, col) && 
		   recorrerDiagonalDerecha(tablero, fila - 1, col + 1);
			
}

bool tableroDeReinas(vector<vector<int>>& tablero, int fila, int filaFin){
	
	// Se  colocaron las n reinas	
	if (fila > filaFin) return true;
	
	
	// Recorremos todas las columnas de esa fila
	for (int col = 0; col < tablero[fila].size(); col++){		
		
		if (verificarValidez(tablero, fila, col)){
			
			tablero[fila][col] = 1;
			
			if (tableroDeReinas(tablero, fila + 1, filaFin)){
				return true;
			}
			
			tablero[fila][col] = 0;	
		}	
	}
	
	return false;
}
	
void imprimirTablero(const vector<vector<int>>& laberinto){
	for (int i = 0; i < laberinto.size(); i++){
		for (int j = 0; j < laberinto[0].size(); j++){
			cout << laberinto[i][j] << " ";
		}
		cout << endl;
	}	
}

int main() {
	vector<vector<int>> tablero(N, vector<int>(N, 0));
	int filaFin = N - 1;
	
	if (tableroDeReinas(tablero, 0, filaFin)){
		imprimirTablero(tablero);
	}
	
	return 0;
}
