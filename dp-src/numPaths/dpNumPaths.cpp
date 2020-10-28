#include <iostream>
#include <vector>

using namespace std;

/*
	The subproblem is how many ways to get to next cell from each cell
	let's do bottom-up iterative approach using memoization
*/

bool isValid(vector<vector<int>>& grid, int r, int c, int m)//m = 0 is left m = 1 is up
{
	if (!m) {
		if (c - 1 >= 0) return true;
	}
	else if (m) {
		if (r - 1 >= 0) return true;
	}
	return false;
}

int numPaths(vector<vector<int>>& grid)
{
	const uint32_t N = grid.size();
	vector<vector<int>> dp(N);
	for (auto& c : dp) c.resize(N);//square matrix/grid (NxN)
	//hard code base case
	dp[0][0] = 1;//1 path to get to the start... we are standing on it
	for (int r{}; r < N; ++r){
		for (int c{0}; c < N; ++c){
			if (!r && !c) c = 1;
			int l_sum{}, u_sum{};
			if (isValid(grid, r, c, 0))//going left (inverse of prob. statement saying going right)
				l_sum = dp[r][c - 1];
			if (isValid(grid, r, c, 1))//going up
				u_sum = dp[r - 1][c];
			dp[r][c] = l_sum + u_sum;
		}
	}
	/*
		Because we have solved all the subproblems, we can calculate the numPaths to ANY
		specific ending square given a starting position of (0,0)
	*/
	return dp[N - 1][N - 1];//num paths to get to bottom right
}


/*
	Run-Time Complexity Analysis:

	# of subproblems X time/subproblem

	#s = N subproblems
	
	[  0,0
	   0,0  ]

	 for every subproblem we are performing 2 constant-time lookups in our memo table
	 therefore O(N) X 2xO(1) = O(N)

	 <1ms for 5x5 grid
	 35ms for 500x500 grid
	 */


int main()
{
	const uint32_t grid_size{ 5 };
	vector<vector<int>> grid(grid_size);
	for (auto& c : grid) c.resize(grid_size);//square matrix/grid with size grid_sizexgrid_size

	int number_of_paths = numPaths(grid);
	cout << "Number of paths from (0,0) to (" << grid_size - 1 << "," << grid_size - 1
		<< ")  : " << number_of_paths << endl;

	cin.get();
	return 0;
}