#include <iostream>
#include <vector>
using namespace std;

void imprimir(const vector<vector<int>>& dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

bool subsetSum(int* arr, int n, int objetivo) {
    // Inicializamos la matriz
    vector<vector<int>> dp(n + 1, vector<int>(objetivo + 1, 0));
    // Siempre es posible obtener la suma 0 seleccionando el subconjunto vacio (columna 0)
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= objetivo; j++) {
            // No incluimos el elemento actual
            dp[i][j] = dp[i - 1][j];

            if (j >= arr[i - 1]) { // ¿por qué j >= arr[i-1] 👀?
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    imprimir(dp);
    return dp[n][objetivo];
}

int main() {
    int arr[] = {2, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 10;

    if (subsetSum(arr, n, objetivo)) {
        cout << "Es posible sumar " << objetivo << endl << endl;
    }
    else {
        cout << "No se puede sumar" << endl;
    }
    return 0;
}
