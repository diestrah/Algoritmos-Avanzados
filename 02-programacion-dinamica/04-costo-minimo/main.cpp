#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void imprimir(const vector<int>& dp) {
    // Imprime el vector de costos acumulados calculados por programacion dinamica
    cout << "Costos: ";
    for (int i=0; i<dp.size(); i++)
        cout << dp[i] << " ";
    cout << endl;
}


int costoMinimo(int* costos, int n) {
    vector<int> dp(n, 0);

    // Inicializamos:
    dp[0] = costos[0];
    dp[1] = costos[1];

    for (int i = 2; i < n; i++) {
        // Sumamos el costo[i] al menor de las sumas acumuladas
        dp[i] = min(dp[i - 1], dp[i - 2]) + costos[i];
    }

    imprimir(dp);

    return dp[n - 1];
}

int main() {
    int costos[] = {10, 15, 20, 8, 15};
    int n = sizeof(costos) / sizeof(costos[0]);
    int costoMin = costoMinimo(costos, n);
    cout << "Costo minimo: " << costoMin << endl;
    return 0;
}
