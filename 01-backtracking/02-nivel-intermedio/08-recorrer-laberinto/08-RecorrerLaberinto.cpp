/*----------------------------------------------------------------------------------*/
/* Autor: Naim Diestra
/* Fecha: 03/09/2026
/* Descripcion:
/* Este programa compara dos formas de escribir el mismo algoritmo de backtracking
/* para encontrar una solución dentro de un laberinto, desde (0,0)
/* hasta (n-1, m-1). Ambas versiones son funcionalmente idénticas; la diferencia
/* está solo en el estilo de implementación:
/*
/*   V1: Explora las 4 direcciones con 4 bloques if escritos a mano
/*       (derecha, abajo, izquierda, arriba).
/*
/*   V2: Explora las mismas 4 direcciones usando un arreglo de desplazamientos
/*       y un bucle for, evitando la repetición de código.
/*
/* Laberinto de ejemplo:
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

/*---------------------- V1: 4 ifs escritos a mano ----------------------*/
bool RecorrerLaberintoV1(vector<vector<int>>& matriz, int fila, int col, int filaFin, int colFin) {
	// Me excedí de la matriz
	if (fila < 0 || fila > filaFin || col < 0 || col > colFin) return false;
	
	// Si es pared o ya fue visitada: hacer
	if (matriz[fila][col] != 1) return false;

	// Hacer: marcamos el recorrido
	matriz[fila][col] = 2;

	// Llegué al destino
	if (fila == filaFin && col == colFin) return true;

	// Exploramos las posibilidades:
	if (RecorrerLaberintoV1(matriz, fila, col + 1, filaFin, colFin)) return true; // Derecha
	if (RecorrerLaberintoV1(matriz, fila + 1, col, filaFin, colFin)) return true; // Abajo
	if (RecorrerLaberintoV1(matriz, fila, col - 1, filaFin, colFin)) return true; // Abajo
	if (RecorrerLaberintoV1(matriz, fila - 1, col, filaFin, colFin)) return true;	// Arriba

	// Si no funcionó ningún método, deshacemos el 2 (marcamos como no recorrido)
	matriz[fila][col] = 1;

	return false;
}


/*---------------------- V2: arreglo de movimientos + bucle ----------------------*/

// Desplazamientos posibles: derecha, abajo, izquierda, arriba
const int dFila[] = {0, 1, 0, -1};
const int dCol[]  = {1, 0, -1, 0};

bool RecorrerLaberintoV2(vector<vector<int>>& matriz, int fila, int col, int filaFin, int colFin) {
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

	// Exploramos las 4 direcciones usando el arreglo de desplazamientos
	for (int i = 0; i < 4; i++) {
		if (RecorrerLaberintoV2(matriz, fila + dFila[i], col + dCol[i], filaFin, colFin)) {
			return true;
		}
	}

	// Si no funcionó ningún método, deshacemos el 2 (marcamos como no recorrido)
	matriz[fila][col] = 1;

	return false;
}

void imprimirLaberinto(const vector<vector<int>>& laberinto) {
	for (size_t i = 0; i < laberinto.size(); i++) {
		for (size_t j = 0; j < laberinto[0].size(); j++) {
			cout << laberinto[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int>> matrizBase = {
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};

	int filaFin = matrizBase.size() - 1;
	int colFin = matrizBase[0].size() - 1;

	// V1
	cout << "V1: 4 ifs escritos a mano" << endl;
	vector<vector<int>> matrizV1 = matrizBase; // copia para no afectar la original

	if (RecorrerLaberintoV1(matrizV1, 0, 0, filaFin, colFin)) {
		cout << "Exito: se llego al final" << endl;
	} else {
		cout << "No se llego al final" << endl;
	}
	imprimirLaberinto(matrizV1);
	cout << endl;


	// V2
	cout << "V2: arreglo de movimientos + bucle" << endl;
	vector<vector<int>> matrizV2 = matrizBase; // copia limpia, sin marcas de V1

	if (RecorrerLaberintoV2(matrizV2, 0, 0, filaFin, colFin)) {
		cout << "Exito: se llego al final" << endl;
	} else {
		cout << "No se llego al final" << endl;
	}
	imprimirLaberinto(matrizV2);

	return 0;
}