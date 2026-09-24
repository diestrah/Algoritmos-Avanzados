#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(1000, -1);

int fibonacci(int n){
	if (n <= 1) return n;
	
	if (dp[n] != -1) return dp[n];
		
	dp[n] = fibonacci(n-1) + fibonacci(n-2);
	
	return dp[n];
}

int main(){
	int n = 4;
	cout << fibonacci(n) << endl;	
	return 0;
}