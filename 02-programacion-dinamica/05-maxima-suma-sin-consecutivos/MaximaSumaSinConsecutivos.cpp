
#include <iostream>
#include <algorithm>
using namespace std;

int maximaSuma(int arr[], int n){
	int dp[n];
	dp[0] = arr[0];
	dp[1] = arr[1];
	
	for (int i = 2; i<n; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
	}
	
	return dp[n-1];
}

int main() {
	int arr[] = {3, 2, 7, 11, 5, 10};
	int n = sizeof(arr) / sizeof(arr[0]);	
	
	cout << maximaSuma(arr, n) << endl;
	
	return 0;
}