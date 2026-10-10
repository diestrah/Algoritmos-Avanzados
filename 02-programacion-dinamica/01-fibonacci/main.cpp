#include <iostream>
#include <vector>
using namespace std;

/*------------Solución TopDown----------------*/
// Se declara una variable global para facilitar la recursión
vector<int> dp(1000, -1);

int fibonacciTopDown(int n) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibonacciTopDown(n - 1) + fibonacciTopDown(n - 2);
    return dp[n];
}

/*------------Solución BottomUp----------------*/
int fibonacciBottomUp(int n) {
    vector<int> dp(n, 0);
    for (int i=0; i<n; i++) {
        if (i<=1) dp.at(i) = 1;
        else dp.at(i) = dp.at(i-1) + dp.at(i-2);
    }
    return dp.at(n-1);
}

int main() {
    int n = 7;
    cout << fibonacciTopDown(n) << endl;
    cout << fibonacciBottomUp(n) << endl;
    return 0;
}