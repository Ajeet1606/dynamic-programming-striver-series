//                              Recusrion
//                           O(exponential) & O(n)

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int fun(int idx, vector<int>&arr){
        if(idx == 0) return arr[0];
        if(idx < 0) return 0;
        
        int pick = arr[idx] + fun(idx-2, arr);
        int skip = fun(idx-1, arr);
        
        return max(pick, skip);
    }
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        
        return fun(n-1, arr);
    }
};


//                                  Memoization
//                                  O(n) & O(n)


class Solution {
public:
    vector<int>dp;
    int fun(int idx, vector<int>&arr){
        //base cases
        if(idx == 0) return arr[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        //pick don't
        int pick = arr[idx] + fun(idx-2, arr);
        //don't pick
        int skip = fun(idx-1, arr);
        //store and return
        return dp[idx] = max(pick, skip);
    }
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n, -1);
        return fun(n-1, arr);
    }
};


//                              Tabulation
//                              O(n) & O(n)

class Solution {
public:    
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n, 0);
        dp[0] = arr[0];
        
        for(int i=1; i<n; i++){
            int take = arr[i];
            if(i>1) take += dp[i-2];
            
            int skip = dp[i-1];
            
            dp[i] = max(take, skip);
            cout<<dp[i];
        }    
        
        return dp[n-1];
    }
};


//                          Space Optimized
//                          O(n) & O(1)

class Solution {
public:    
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        int prev2 = 0, prev = arr[0];
        
        for(int i=1; i<n; i++){
            int take = arr[i] + prev2;
            
            int skip = prev;
            
            int curr = max(take, skip);
            prev2 = prev;
            prev = curr;
        }    
        
        return prev;
    }
};