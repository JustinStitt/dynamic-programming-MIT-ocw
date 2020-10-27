#include <iostream>
#include <vector>
using namespace std;


int numWays(int n) {
	/*
		number of ways to reach the top of a staircase with 'n' steps 
		by taking either 1 or 2 steps at a time. However, you may not take 1-step twice
		in a row.
	*/
	vector<vector<int>> dp(n);

	dp[0].push_back(0);//step 0
	dp[1].push_back(1);//step 1 took 1-step from step 0

	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < dp[i - 1].size(); ++j) {
			if (dp[i - 1][j] != 1)
				dp[i].push_back(1);
		}
		for (int j = 0; j < dp[i - 2].size(); ++j) {
			dp[i].push_back(2);
		}
	}
	return dp[n - 1].size();
}


int main()
{
	cout << numWays(4) << endl;
	cin.get();
	return 0;
}