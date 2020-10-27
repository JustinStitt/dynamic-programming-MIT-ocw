#include <iostream>

using namespace std;


int fib(int n) {
	int* dp = new int[n];
	dp[0] = 0;
	dp[1] = 1;
	for (int x = 2; x < n; ++x)
	{
		dp[x] = dp[x - 1] + dp[x - 2];
	}
	return dp[n - 1];
}


int main()
{
	cout << fib(8) << endl;
	cin.get();
	return 0;
}