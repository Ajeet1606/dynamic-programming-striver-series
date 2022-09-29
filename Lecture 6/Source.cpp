//                  Pretty much similar to HOUSE ROBBER 1
//            Condition is that we can't pick first and last elements simulatenously.
//          So, we make separate arrays, one without first and second without last elements.
//          Now, we calculate separately, with the same logic..



class Solution {
public:
    
    int fun(int n, vector<int>& arr){
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
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        vector<int>temp1, temp2;
        for(int i=0; i<n; i++){
            if(i!=0)
                temp1.push_back(arr[i]);
            if(i!= n-1)
                temp2.push_back(arr[i]);
        }
        
        return max(fun(n-1, temp1), fun(n-1, temp2));
    }
};