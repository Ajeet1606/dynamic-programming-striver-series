//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<------------------------Recursion-------------------------->>>>>>>>>>>>>>>>>>>>>>>
//											O(2^mn) and O(m+n)

int fun(int i, int j, vector<vector<int>>&grid){
	if(i == 0 and j == 0) return 1;
	if(i < 0 or j < 0) return 0;
    if(grid[i][j] == -1) return 0;

	int up = fun(i-1, j);
	int left = fun(i, j-1);

	return up + left;
}

int main(){
	vector<vector<int>>grid;
	int m = grid.size(), n = grid[0].size();
	cout<<fun(m-1, n-1, grid);
	
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-----------------------Memoization------------------------->>>>>>>>>>>>>>>>>>>>>>>>
//										O(mn) and O((m+n) + (mn))

int fun(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid){
	//Base Case
	if(i == 0 and j == 0) return 1;
	if(i < 0 or j < 0) return 0;
    if(grid[i][j] == -1) return 0;

	//already found
	if (dp[i][j] != -1){
		return dp[i][j];
	}

	//calculate
	int up = fun(i-1, j, dp);
	int left = fun(i, j-1, dp);

	//store and return
	return dp[i][j] = up+ left;
}

int main(){
	vector<vector<int>>grid;
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>>dp(m, vector<int>(n, -1));
	cout<<fun(m-1, n-1, dp);
	
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<---------------------Tabulation------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>
//									To reduce stack space: O(mn) and O(mn)


int main() {

    vector<vector<int>>grid;
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>>dp(m, vector<int>(n, 0));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; j++) {
			if (i == 0 and j == 0) {
				dp[i][j] = 1;
			}
            if(grid[i][j] == -1) dp[i][j] = 0;
			else {
				int up = 0, left = 0;
				if (i > 0)
					up = dp[i - 1][j];
				if (j > 0)
					left = dp[i][j - 1];

				dp[i][j] = up + left;
			}
		}
	}

	cout << dp[m - 1][n - 1];

}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-----------------------Space optimized---------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>
//											 O(mn) and O(n)

int main() {

    vector<vector<int>>grid;
	int m = grid.size(), n = grid[0].size();
	vector<int>prev(n, 0);

	for (int i = 0; i < m; ++i) {
		vector<int>curr(n, 0);
		for (int j = 0; j < n; j++) {
			if (i == 0 and j == 0) {
				curr[j] = 1;
			}
            if(grid[i][j] == -1) curr[j] = 0;
			else {
				int	up = prev[j];
				int left = 0;
				if (j > 0)
					left = curr[j - 1];

				curr[j] = up + left;
			}
		}
		prev = curr;
	}

	cout << prev[n - 1];

}