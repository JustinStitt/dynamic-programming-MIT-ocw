#include <iostream>
#include <vector>
using namespace std;

int minCoins(int n) {
	/*
		use the minimum amount of coins to equal N
		coins = {1,5,10,25}
	*/
	int coins[]{ 1,5,10,25 };
	vector<int> dp(n + 1, INT_MAX);//for minimization problems, set to inf
	//base case
	dp[0] = 0;//to make sum 0 you use 0 coins

	for (int x = 1; x < n + 1; ++x) {//solve the subproblems so that we can solve for n eventually
		//for each subproblem, find out which coin we can use and minimize it
		for (int j{}; j < 4 ; ++j) {
			if (x - coins[j] < 0) break;
			dp[x] = min(dp[x], dp[x - coins[j]] + 1);
		}
	}
	return dp[n];
}


int main()
{
	cout << minCoins(100) << endl;
	cin.get();
	return 0;
}