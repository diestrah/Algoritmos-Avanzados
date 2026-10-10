#include <iostream>
#include <vector>
using namespace std;

void imprimir(const vector<int>& arr, int objetivo) {
    for (int i = 0; i <= objetivo; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool subsetSum(int arr[], int n, int objetivo) {
    // Inicializamos
    vector<int> dp(objetivo + 1, 0);
    dp[0] = 1;  // Caso base: siempre es posible obtener la suma 0

    for (int i = 0; i < n; i++) {
        for (int j = objetivo; j >= arr[i]; j--) {
            // Podemos obtener la suma j si ya era posible obtenerla
            // sin el elemento actual, o si podemos obtener j - arr[i]
            // utilizando los elementos anteriores y agregar arr[i].
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    imprimir(dp, objetivo);
    return dp[objetivo];
}

int main() {
    int arr[] = {2, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 10;

    if (subsetSum(arr, n, objetivo)) {
        cout << "Es posible sumar " << objetivo << endl << endl;
    }

    return 0;
}
