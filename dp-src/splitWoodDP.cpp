#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& lengths, vector<int>& prices, int N)
{
	/*
		what are the subproblems?
		lets find the max profit from each length from [1...N]
		bottom-up approach
	*/
	vector<vector<int>> dp(lengths.size() + 1);
	for (auto& r : dp) r.resize(N + 1);

	for (int r = 1; r < dp.size(); ++r)
	{
		for (int c = 1; c < dp[r].size(); ++c)
		{
			//check if we can even cut the wood by the length (if we cant, we dont even decide to include it or not)
			if (lengths[r - 1] > c)//we are trying to cut by something larger than N
				dp[r][c] = dp[r - 1][c];//set equal to previous best
			else {//else we have the option of whether or not to use this length
				int price = (c / lengths[r - 1]) * prices[r - 1];
				int rem = c % lengths[r - 1];
				dp[r][c] = max(
						dp[r-1][c],//what came before (p-best for this length 'c')
					price + dp[r-1][rem]//how much we can make with this length cut with how much is remaining after
				);
			}
		}
	}
	return dp[lengths.size()][N];
}

/*
	Given some length of wood, N, and prices for specific lengths
	what is the most profitable way to cut and sell the wood

	L|1 2 3 4 ...
	-|-------------
	P|2 3 7 14 ...

*/

int main()
{
	vector<int> lengths{ 1,2,3,4 };
	vector<int> prices{ 1,2,4,4};
	int wood_length = 8;

	int res = maxProfit(lengths, prices, wood_length);
	cout << "max profit: " << res << endl;

	cin.get();
	return 0;
}