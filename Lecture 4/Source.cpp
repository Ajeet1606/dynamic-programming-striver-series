
//FROG JUMP Problem

#include <bits/stdc++.h>
using namespace std;

// ------------------------------ RECURSION APPROACH -> O(N^K) & O(N) ----------------------------------------


int fun(int idx, int &k, vector<int>&heights){
	
	if(idx == 0) return 0;

	int ans = INT_MAX;
	for(int j=0; j<k; j++){
		if(idx - j >= 0){
			int cost = fun(idx-j, k, heights) + abs(heights[j] - heights[idx-j]); 
			ans = min(ans, cost);
		}
	}
	return ans;
}

int main(){
	int n = 4, k = 2;
	vector<int>heights = {10, 20, 30, 10};
	cout<<fun(n-1, k, heights);
}



//----------------------------------  Memoization approach  O(N*K) & O(N) ------------------------------------------

vector<int>dp;
int fun(int idx, int &k, vector<int>&heights){
	
	if(idx == 0) return 0;
	if (dp[idx] != -1){
		return dp[idx];
	}
	int ans = INT_MAX;
	for(int j=0; j<k; j++){
		if(idx - j >= 0){
			int cost = fun(idx-j, k, heights) + abs(heights[j] - heights[idx-j]); 
			ans = min(ans, cost);
		}
	}
	return dp[idx] = ans;
}

int main(){
	int n = 4, k = 2;
    dp.resize(n+1, -1);
	vector<int>heights = {10, 20, 30, 10};
	cout<<fun(n-1, k, heights);
}

//----------------------------------- Tabulation Approach O(N*K) & O(N) ------------------------------------


int main(){

	int n = 4, k=2;
    vector<int>dp(n, 0);
	
	vector<int>heights = {10, 20, 30, 10};
	
	for (int i = 1; i < n; ++i){
		int ans = INT_MAX;
		for(int j=0; j<k; j++){
			if(i - j >= 0){
				int cost = dp[i-j] + abs(heights[i] - heights[i-j]);
				ans = min(ans, cost);
			}
		}
		dp[i] = ans;
	}

	cout<<dp[n-1];
}

