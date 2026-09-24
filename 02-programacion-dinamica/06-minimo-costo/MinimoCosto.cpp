#include <iostream>
#include <algorithm>
using namespace std;


void imprimirCostos(int dp[], int n){
	for (int i=0; i<n; i++)
		cout << dp[i] << " ";
	cout << endl;
}

int costoMinimo(int costos[], int n){
	int dp[n];
	dp[0] = 0;
	dp[1] = costos[0];
	
	for (int i=1; i<=n; i++) {
		dp[i] = costos[i] + min(dp[i-1], dp[i-2]);
	}
	
	imprimirCostos(dp, n);
	
	return dp[n-1];
}

int main() {
	int costos[] = {10, 15, 20, 8, 15};
	int n = sizeof(costos) / sizeof(costos[0]);
	
	cout << "Costo minimo: " << costoMinimo(costos, n) << endl;

	return 0;
}