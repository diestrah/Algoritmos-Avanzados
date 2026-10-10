#include <iostream>
#include <vector>
#include <string>
using namespace std;

void imprimir(const vector<vector<int>>& dp) {
    int size = dp.size();
    cout << "Estados: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

string buscarPalindromo(const string& palabra) {
    int size = palabra.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));

    int mejorInicio = 0;
    int mejorLongitud = 1;

    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
    }

    // Evaluar subcadenas de longitud 2 en adelante.
    for (int i = size - 1; i >= 0; i--) {
        for (int j = i + 1; j < size; j++) {
            if (palabra[i] == palabra[j]) {
                // Longitud 2 o 3: el interior es vacío
                // o contiene un solo carácter.
                if (j - i <= 2) {
                    dp[i][j] = 1;
                }
                // Longitud mayor: depende del interior.
                else if (dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                }
            }

            if (dp[i][j] == 1 && j - i + 1 > mejorLongitud) {
                mejorInicio = i;
                mejorLongitud = j - i + 1;
            }
        }
    }

    imprimir(dp);
    return palabra.substr(mejorInicio, mejorLongitud);
}

int main() {
    string palabra = "SOLILOLPLALI";
    string palindromo = buscarPalindromo(palabra);
    cout << "Palindromo: " << palindromo << endl;
    return 0;
}
