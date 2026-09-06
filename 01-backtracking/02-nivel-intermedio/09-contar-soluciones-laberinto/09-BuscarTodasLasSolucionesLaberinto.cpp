/*----------------------------------------------------------------------------------*/
/* Autor: Naim Diestra
/* Fecha: 03/09/2026
/* Descripcion:
/* Este programa implementa una función la cual cuenta todas las soluciones de un 
/* laberinto. Para su solución debe utilizarse backtracking.
/* Se considera que llegó al fin cuando inicia en (0,0) y termina en (n-1, m-1)
/* Ejemplo:
/* Para el laberinto
/*		[1 1 1 0]
/*  	[1 1 1 1]
/*  	[0 1 0 1]
/*  	[1 1 1 1]
/* Cantidad de soluciones: 7
/*----------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

int BuscarTodasLasSolucionesLaberinto(vector<vector<int>>& laberinto, int fila, int col, int filaFin, int colFin) {
	// Se excedió del limite
	if (fila < 0 || fila > filaFin || col < 0 || col > colFin ){
		return 0;
	}
	
	if (laberinto[fila][col] != 1) {
		return 0;
	}
	
	// Hacer: marcamos como visitada
	laberinto[fila][col] = 2;	
	
	// Llegó al final
	if (fila == filaFin && col == colFin) {
		laberinto[fila][col] = 1;	// deshacemos, de lo contrario, solo tomaría una solución, investigar el por qué d:
		return 1;
	}
	
	
	laberinto[fila][col] = 2;
	
	int sol = 0;
	
	sol += BuscarTodasLasSolucionesLaberinto(laberinto, fila, col + 1, filaFin, colFin);
	sol += BuscarTodasLasSolucionesLaberinto(laberinto, fila + 1, col, filaFin, colFin);
	sol += BuscarTodasLasSolucionesLaberinto(laberinto, fila, col - 1, filaFin, colFin);
	sol += BuscarTodasLasSolucionesLaberinto(laberinto, fila - 1, col, filaFin, colFin);
	
	laberinto[fila][col] = 1;

	return sol;
}


int main() {
	
	vector<vector<int>> laberinto = {
    	{1, 1, 1, 0},
    	{1, 1, 1, 1},
    	{0, 1, 0, 1},
    	{1, 1, 1, 1}
	};
	
	int filaFin = laberinto.size() - 1;
	int colFin = laberinto[0].size() - 1;
	
	int sol = BuscarTodasLasSolucionesLaberinto(laberinto, 0, 0, filaFin, colFin);
	cout << "soluciones: " << sol << endl;
	
	return 0;
}