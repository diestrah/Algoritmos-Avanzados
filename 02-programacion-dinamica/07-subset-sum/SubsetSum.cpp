#include <iostream>
#include <vector>
using namespace std;


bool subsetSumV1(int arr[], int n, int objetivo){
	
	int dp[n+1][objetivo+1] {};
	
	for (int i=0; i<=n; i++) dp[i][0] = 1;
	
	
	for (int i=1; i<=n; i++){
		
		for (int j=1; j<=objetivo; j++){
		
			dp[i][j] = dp[i-1][j];
			
			if (arr[i-1] <= j) // ¿por qué arr[i-1]?
    			dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
		}
	}

	// Impresión de la matriz	 
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=objetivo; j++) 
			cout << dp[i][j] << "  "; 
		cout << endl;
	}	
	
	return dp[n][objetivo];
}


void imprimir(int arr[], int objetivo){
	for (int i=0; i<=objetivo; i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool subsetSumV2(int arr[], int n, int objetivo) {
	
	int dp[objetivo + 1] = {};
	
	dp[0] = true;
	
	for (int i = 0; i < n; i++){
		
		for (int j = objetivo; j >= arr[i]; j--){
			
			dp[j] = dp[j] || dp[j-arr[i]];
		}
	}
	
	imprimir(dp, objetivo);
	
	return dp[objetivo];
}

int main() {
	int arr[] = {2, 3, 5, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	int objetivo = 10;
	
	if (subsetSumV1(arr, n, objetivo)){
		cout << "Es posible sumar " << objetivo << endl << endl;
	}
	
	if (subsetSumV2(arr, n, objetivo)){
		cout << "Es posible sumar " << objetivo << endl << endl;
	}
	
	return 0;
}