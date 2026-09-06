/*----------------------------------------------------------------------------------*/
/* Autor: Naim Diestra
/* Fecha: 03/09/2026
/* Descripcion:
/* Este programa implementa una función la cual cuenta todas las soluciones de un 
/* laberinto. Para su solución debe utilizarse backtracking.
/* Se considera que llegó al fin cuando inicia en (0,0) y termina en (n-1, m-1)
/* Ejemplo:
/* Para el laberinto
/*		[1, 0, 0, 0]
/*		[1, 1, 0, 1]
/*		[0, 1, 0, 0]
/*		[1, 1, 1, 1]
/*		
/* El recorrido es:
/*		[2, 0, 0, 0]
/*		[2, 2, 0, 1]
/*		[0, 2, 0, 0]
/*		[1, 2, 2, 2]
/*----------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

bool RecorrerLaberinto(vector<vector<int>>& matriz, int fila, int col, int filaFin, int colFin){
	// Me excedí de la matriz
	if (fila < 0 || fila > filaFin || col < 0 || col > colFin) {
		return false;	
	}
	
	// Si es pared o ya fue visitada: hacer
	if (matriz[fila][col] != 1) {
		return false;
	}
	
	// Hacer: marcamos el recorrido
	matriz[fila][col] = 2;
	
	// Llegué al destino
	if (fila == filaFin && col == colFin) {
		return true;
	}
	
	
	// Exploramos las posibilidades:
	// Derecha
	if (RecorrerLaberinto(matriz, fila, col + 1, filaFin, colFin)){
		return true;
	}
	
	// Abajo
	if (RecorrerLaberinto(matriz, fila + 1, col, filaFin, colFin)){
		return true;
	}
	
	// Izquierda
	if (RecorrerLaberinto(matriz, fila, col - 1, filaFin, colFin)){
		return true;
	}
	
	// Arriba
	if (RecorrerLaberinto(matriz, fila - 1, col, filaFin, colFin)){
		return true;
	}
	
	// Si no funcionó ningún método, deshacemos el 2 (marcamos como no recorrido)
	matriz[fila][col] = 1;
	
	return false;
}
	
void imprimirLaberinto(const vector<vector<int>>& laberinto){
	for (int i = 0; i < laberinto.size(); i++){
		for (int j = 0; j < laberinto[0].size(); j++){
			cout << laberinto[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main() {
	vector <vector<int>> matriz = {
									{1, 0, 0, 0},
									{1, 1, 0, 1},
									{0, 1, 0, 0},
									{1, 1, 1, 1}
	};

	// Límites recorribles de la matriz
	int filaFin = matriz.size() - 1;
	int colFin = matriz[0].size() - 1;	


	if (RecorrerLaberinto(matriz, 0, 0, filaFin, colFin)){
		cout << "Exito: se llegó al final" << endl;	
	}	
	else {
		cout << "No se llegó al final" << endl;
	}
	
	imprimirLaberinto(matriz);
	
	return 0;
}

