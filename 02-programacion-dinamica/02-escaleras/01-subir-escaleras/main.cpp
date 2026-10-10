#include <iostream>
#include <vector>
using namespace std;

int subirEscalones(int escalones) {
    if (escalones < 0) return 0;

    // dp[i] representa la cantidad de formas de llegar al escalon i
    vector<int> dp(escalones + 1, 0);

    // Inicializamos:
    dp[0] = 1; // Se puede llegar al escalón 0 no dando ningún salto
    if (escalones >= 1) dp[1] = 1; // Solo se puede llegar al primer escalon dando un salto de 1

    for (int i = 2; i <= escalones; i++) {
        // Para llegar al escalon i, podemos venir desde i-1 o desde i-2
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Devolvemos la cantidad total de formas en que se llegó al último escalón
    return dp[escalones];
}

int main() {
    int escalones = 6;
    cout << subirEscalones(escalones) << " formas" << endl;
    return 0;
}