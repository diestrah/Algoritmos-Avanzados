/*
	Ejercicio de las escaleras.
	Tienes una escalera de n escalones.
	Tienes solo 2 movimientos: 
	  - subir 1 escalón
	  - subir 2 escalones
	¿De cuántas formas se pueden subir n escalones?

	Ej. Escalones = 4
	1 1 1 1 
	1 1 2 
	1 2 1
	2 1 1
	2 2
	
	-> Resultado: 5 formas
*/
#include <iostream>
using namespace std;

int subirEscalones(int escalones) {
	// Cada elemeto del arreglo representa las formas en las que puedo llegar al escalón i
    int dp[escalones + 1] = {};
	
	// Casos base
    dp[0] = 1; // Puedo ir al escalón 0 de 1 forma
    dp[1] = 1; // Puedo ir al escalón 1 de 1 forma

    for (int i = 2; i <= escalones; i++) {
	    // Puedo llegar al escalón i de:
		// todas las formas que llegué al escalón i-1 y subir 1 +
		// todas las formas que llegué al escalón i-2 y subir 2 + 
        dp[i] = dp[i - 1] + dp[i - 2]; 
    }

    return dp[escalones];
}

int main() {
    int escalones = 4;

    cout << subirEscalones(escalones) << endl;

    return 0;
}
