#include <iostream>
#include <vector>
using namespace std;

#define PASOS 4

int subirEscalones(int escalones) {
    if (escalones < 0) return 0;

    // dp[i] representa la cantidad de formas de llegar al escalon i.
    // Se reserva una posicion adicional para representar el escalon 0.
    vector<int> dp(escalones + 1, 0);

    dp[0] = 1; // La única forma de llegar al escalón 0 es no dar ningun salto.

    // Iteración que recorre los escalones y calcula las formas de llegar a cada uno.
    for (int i = 1; i <= escalones; i++) {
		
        // Iteración que considera todos los saltos posibles, desde 1 hasta PASOS
        for (int j = 1; j <= PASOS && j <= i; j++) {
            // Cada forma de llegar desde un escalon anterior
            // contribuye al total de formas de llegar al escalon actual
            dp[i] += dp[i - j];
        }
    }

    // Devuelve la cantidad total de formas de subir la escalera.
    return dp[escalones];
}

int main() {
    int escalones = 6;
    cout << subirEscalones(escalones) << " formas" << endl;
    return 0;
}