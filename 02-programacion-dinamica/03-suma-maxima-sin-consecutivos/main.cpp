#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sumaMaximaSinConsecutivos(int* arr, int n) {
    vector<int> dp(n, 0);

    // Inicializamos:
    dp[0] = arr[0];
    dp[1] = arr[1];

    for (int i = 2; i < n; i++) {
        // Seleccionamos el mayor entre el elemento i-1
        // o la suma del i-2 más el actual (arr[i])
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    return dp[n - 1];
}

int main() {
    int arr[] = {3, 2, 7, 11, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Suma maxima sin consecutivos: " <<
        sumaMaximaSinConsecutivos(arr, n) << endl;
    return 0;
}
