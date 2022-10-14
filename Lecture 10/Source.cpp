//---------------------------------Recursion-----------------------------------
//						O(2^rc) and O(r+c)

int fun(int i, int j, vector<vector<int>>&grid) {
	//Base Case
	if (i == 0 and j == 0) return grid[0][0];
	if (i < 0 or j < 0) return 1e9;

	int up = fun(i-1, j, grid);
	int left = fun(i, j-1, grid);

	return grid[i][j] + min(up, left);
}

int main() {

	vector<vector<int>>grid = {{1,3,1}, {1,5,1}, {4,2,1}};
	int rows = grid.size(), cols = grid[0].size();
	cout<<fun(rows-1, cols-1, grid);
}



//------------------------------Memoization--------------------------------------------
//					   O(rc) and O(rc + path length)

int fun(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp) {
	//Base Case
	if (i == 0 and j == 0) return grid[0][0];
	if (i < 0 or j < 0) return 1e9;

	//already calculated
	if(dp[i][j] != -1) return dp[i][j];

	//let's find out
	int up = fun(i-1, j, grid, dp);	//go up
	int left = fun(i, j-1, grid, dp);	//go left

	//save and return
	return dp[i][j] = grid[i][j] + min(up, left);
}

int main() {

	vector<vector<int>>grid = {{1,3,1}, {1,5,1}, {4,2,1}};
	int rows = grid.size(), cols = grid[0].size();
	vector<vector<int>>dp(rows, vector<int>(cols, -1));
	cout<<fun(rows-1, cols-1, grid, dp);
}



//----------------------------------Tabulation----------------------------------------
//						 O(rc) and O(r+c)

int main() {

	vector<vector<int>>grid = {{1,3,1}, {1,5,1}, {4,2,1}};
	int rows = grid.size(), cols = grid[0].size();
	vector<vector<int>>dp(rows, vector<int>(cols, 0));
	
	for (int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			if (i == 0 and j == 0) dp[i][j] = grid[0][0];
			else{
				int up = 1e9;
				if(i > 0)
					up = dp[i-1][j];
				int left = 1e9;
				if(j > 0)
					left = dp[i][j-1];

				dp[i][j] = grid[i][j] + min(up, left);
			}
		}
	}

	cout<<dp[rows-1][cols-1];
}


//-------------------------------Space optimized--------------------------------------------
//						 O(rc) and O(c)

int main() {

	vector<vector<int>>grid = {{1,3,1}, {1,5,1}, {4,2,1}};
	int rows = grid.size(), cols = grid[0].size();
	vector<int>prev(cols, 0);
	
	for (int i = 0; i < rows; ++i){
		vector<int>curr(cols, 0);
		for(int j = 0; j < cols; ++j){
			if (i == 0 and j == 0) curr[j] = grid[0][0];
			else{
				int up = 1e9;
				if(i > 0)
					up = prev[j];
				int left = 1e9;
				if(j > 0)
					left = curr[j-1];

				curr[j] = grid[i][j] + min(up, left);
			}
		}
		prev = curr;
	}

	cout<< prev[cols-1];
}