#include <iostream>
#include <vector>

using namespace std;

bool validMove(vector<vector<int>>& grid, int x, int y, int m)//m = 0 is down, m = 1 is right
{
	if (m == 0) {
		if (y + 1 <= grid.size() - 1) return true;
	}
	else if (m == 1) {
		if (x + 1 <= grid[y].size() - 1) return true;
	}
	return false;
}

bool atEnd(vector<vector<int>>& grid, int x, int y) 
{
	if (y == grid.size() - 1 && x == grid[y].size() - 1) return true;//x,y is bottom right of grid
	return false;
}

int numPaths(vector<vector<int>>& grid, int x, int y)
{
	//recursive base case
	if (atEnd(grid,x,y)) return 1;
	//otherwise we need to make some move
	int p_down{}, p_right{};
	if (validMove(grid, x, y, 0))//can we move down?
		p_down = numPaths(grid, x, y + 1);
	if (validMove(grid, x, y, 1))//can we move right?
		p_right = numPaths(grid, x + 1, y);
	return p_down + p_right;//at each cell, find how many paths reach the end going down and how
	//many reach the end going right
}


int main()
{
	uint32_t grid_size = 25;
	vector<vector<int>> grid(grid_size);;  
	for (auto& r : grid) r.resize(grid_size);

	int number_of_paths = numPaths(grid, 0, 0);
	cout << "Number of paths from (0,0) to (" << grid_size - 1 << "," << grid_size - 1 << ") : "
		<< number_of_paths << endl;

	cin.get();
	return 0;
}