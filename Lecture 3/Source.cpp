
//FROG JUMP Problem

#include <bits/stdc++.h>
using namespace std;

// ------------------------------ RECURSION APPROACH -> O(N^2) & O(N) ----------------------------------------


int fun(int idx, vector<int>&heights){
	
	if(idx == 0) return 0;

	int first = fun(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
	int second = INT_MAX;
	if(idx > 1){
		second = fun(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
	}

	return min(first, second);
}

int main(){
	int n = 4;
	vector<int>heights = {10, 20, 30, 10};
	cout<<fun(n-1, heights);
}



//------------------------------------Memoization approach  O(N) & O(N)---------------------------------------------

vector<int>dp;
int fun(int idx, vector<int>&heights){
	
	if(idx == 0) return 0;
	if (dp[idx] != -1){
		return dp[idx];
	}
	int first = fun(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
	int second = INT_MAX;
	if(idx > 1){
		second = fun(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
	}

	return dp[idx] = min(first, second);
}

int main(){
	int n = 4;
    dp.resize(n+1, -1);
	vector<int>heights = {10, 20, 30, 10};
	cout<<fun(n-1, heights);
}

//----------------------------------- Tabulation Approach O(N) & O(N) ------------------------------------


int main(){

	int n = 4;
    vector<int>dp(n, 0);
	
	vector<int>heights = {10, 20, 30, 10};
	
	for (int i = 1; i < n; ++i){
		int fs = dp[i-1] + abs(heights[i] - heights[i-1]);

		int ss = INT_MAX;
		if(i>1){
			ss = dp[i-2] + abs(heights[i] - heights[i-2]);
		}

		dp[i] = min(fs, ss);
	}

	cout<<dp[n-1];
}


// --------------------------------- Space Optimized -> O(n) & O(1) ------------------------------------

int main(){

	int n = 4;
	
	vector<int>heights = {10, 20, 30, 10};
	
	
	int prev = 0, prev2 = 0;

	for (int i = 1; i < n; ++i){
		int fs = prev + abs(heights[i] - heights[i-1]);

		int ss = INT_MAX;
		if(i>1){
			ss = prev2 + abs(heights[i] - heights[i-2]);
		}
		int curr = min(fs, ss);

		prev2= prev;
		prev = curr;
	}

	cout<<prev;
}