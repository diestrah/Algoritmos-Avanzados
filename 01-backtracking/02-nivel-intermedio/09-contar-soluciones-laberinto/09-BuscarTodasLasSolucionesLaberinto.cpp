/*----------------------------------------------------------------------------------*/
/* Autor: Naim Diestra
/* Fecha: 03/09/2026
/* Descripcion:
/* Este programa implementa una función que cuenta TODAS las soluciones de un
/* laberinto, utilizando backtracking. Se considera que llegó al fin cuando
/* inicia en (0,0) y termina en (n-1, m-1). Los movimientos permitidos son
/* los 4 ortogonales: derecha, abajo, izquierda, arriba (no diagonales).
/*
/* Se muestran dos versiones equivalentes del mismo algoritmo:
/*   V1: Explora las 4 direcciones con 4 sumas escritas a mano.
/*   V2: Explora las mismas 4 direcciones usando un arreglo de desplazamientos
/*       y un bucle for, evitando la repetición de código.
/*
/* Nota clave de backtracking: al llegar al destino, se deshace su marca de
/* "visitado" (laberinto[fila][col] = 1) ANTES de contar y retornar. Si no se
/* hiciera, otros caminos que también intenten llegar a esa misma celda destino
/* la encontrarían marcada como visitada y la descartarían como si fuera pared,
/* perdiendo soluciones válidas.
/*
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

/*---------------------- V1: 4 sumas escritas a mano ----------------------*/
int BuscarTodasLasSolucionesV1(vector<vector<int>>& laberinto, int fila, int col, int filaFin, int colFin) {
	// Se excedió del límite
	if (fila < 0 || fila > filaFin || col < 0 || col > colFin) return 0;
	
	// Es pared o ya fue visitada
	if (laberinto[fila][col] != 1) return 0;

	// Hacer: marcamos como visitada
	laberinto[fila][col] = 2;

	// Llegó al final
	if (fila == filaFin && col == colFin) {
		laberinto[fila][col] = 1; // deshacemos el marcado y exploramos otras soluciones
		return 1;
	}

	int sol = 0;
	sol += BuscarTodasLasSolucionesV1(laberinto, fila, col + 1, filaFin, colFin);
	sol += BuscarTodasLasSolucionesV1(laberinto, fila + 1, col, filaFin, colFin);
	sol += BuscarTodasLasSolucionesV1(laberinto, fila, col - 1, filaFin, colFin);
	sol += BuscarTodasLasSolucionesV1(laberinto, fila - 1, col, filaFin, colFin);

	// Deshacer: liberamos la celda para que otros caminos puedan reutilizarla
	laberinto[fila][col] = 1;
	return sol;
}

/*---------------------- V2: arreglo de movimientos + bucle ----------------------*/
// Desplazamientos posibles: derecha, abajo, izquierda, arriba
const int dFila[] = {0, 1, 0, -1};
const int dCol[]  = {1, 0, -1, 0};

int BuscarTodasLasSolucionesV2(vector<vector<int>>& laberinto, int fila, int col, int filaFin, int colFin) {
	// Se excedió del límite
	if (fila < 0 || fila > filaFin || col < 0 || col > colFin) return 0;
	
	// Es pared o ya fue visitada
	if (laberinto[fila][col] != 1) return 0;
	
	// Hacer: marcamos como visitada
	laberinto[fila][col] = 2;

	// Llegó al final
	if (fila == filaFin && col == colFin) {
		// Deshacemos la marca del destino: si no lo hacemos, otras rutas que
		// también intenten llegar aquí lo verían como "visitado" y se
		// perderían soluciones válidas.
		laberinto[fila][col] = 1;
		return 1;
	}

	// Exploramos las 4 direcciones usando el arreglo de desplazamientos
	int sol = 0;
	for (int i = 0; i < 4; i++) {
		sol += BuscarTodasLasSolucionesV2(laberinto, fila + dFila[i], col + dCol[i], filaFin, colFin);
	}

	// Deshacer: liberamos la celda para que otros caminos puedan reutilizarla
	laberinto[fila][col] = 1;
	return sol;
}

int main() {
	vector<vector<int>> laberintoBase = {
		{1, 1, 1, 0},
		{1, 1, 1, 1},
		{0, 1, 0, 1},
		{1, 1, 1, 1}
	};

	int filaFin = laberintoBase.size() - 1;
	int colFin = laberintoBase[0].size() - 1;

	// V1 
	vector<vector<int>> laberintoV1 = laberintoBase; // copia para no afectar la original
	int solV1 = BuscarTodasLasSolucionesV1(laberintoV1, 0, 0, filaFin, colFin);
	cout << "V1: Se encontraron " << solV1 << " soluciones" << endl;

	// V2
	vector<vector<int>> laberintoV2 = laberintoBase; // copia limpia
	int solV2 = BuscarTodasLasSolucionesV2(laberintoV2, 0, 0, filaFin, colFin);
	cout << "V2: Se encontraron " << solV2 << " soluciones" << endl;

	return 0;
}