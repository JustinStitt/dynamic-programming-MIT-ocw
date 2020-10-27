#include <iostream>

using namespace std;

int numWays(int n) {
	/*
		how many ways can we get to the top of a staircase with n steps
		by only stepping 1 or 2 steps at a time?
	*/
	int* dp = new int[n];
	dp[0] = 0;//first step is 0 ways to get there (empty path)
	dp[1] = 1;//second step has only 1 way to get there (taking 1 step from step 0)
	for (int x = 2; x < n; ++x) {
		dp[x] = dp[x - 1] + dp[x - 2];//each step can be reached from the previous 2 steps
	}
	return dp[n - 1];
}


int main()
{
	cout << numWays(3) << endl;

	cin.get();
	return 0;
}