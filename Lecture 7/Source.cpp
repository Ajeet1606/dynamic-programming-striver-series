<<<<<<<<<<<<<<<<<-----------Recursion----------------->>>>>>>>>>>>>>>>>>>

//last represents the activity performed in last day, we start from 3, as initially there's no last before it.


int fun(int day, int last, vector<vector<int>>&arr){

	//when we reach day0, there's no more after this, so taking the best rewarding activity is best idea.
	if (day == 0){
		int mx = 0;
		for (int i = 0; i < 3; ++i){
			if(i != last)
				mx = max(mx, arr[day][i]);
		}
		return mx;
	}

	//if we pick i'th activity today, we'll get today's points + answer from further days.
	int mx = 0;
	for (int i = 0; i < 3; ++i){
		if(i != last){
			int points = arr[day][i] + fun(day-1, i, arr);
			mx = max(mx, points);
		}
	}

	return mx;
}

int main(){

	vector<vector<int>>arr = {{1,2,5}, 	//day 0
					    {3,1,1}, 	//day 1
					    {3,3,3}};	//day 2

	int days = arr.size();
	
	cout<<fun(days-1, 3, arr);
}


<<<<<<<<<<<<<<<<<<<<<------------------Memoization------------------->>>>>>>>>>>>>>>>>>>>
						  O(n*4*3) & O(n*4)

int fun(int day, int last, vector<vector<int>>&arr, vector<vector<int>>&memo){
	if (day == 0){
		int mx = 0;
		for (int i = 0; i < 3; ++i){
			if(i != last)
				mx = max(mx, arr[day][i]);
		}
		return mx;
	}

	if (memo[day][last] != -1){
		return memo[day][last];
	}

	int mx = 0;
	for (int i = 0; i < 3; ++i){
		if(i != last){
			int points = arr[day][i] + fun(day-1, i, arr, memo);
			mx = max(mx, points);
		}
	}

	return memo[day][last] = mx;
}

int main(){

	vector<vector<int>>arr = {{1,2,5}, {3,1,1}, {3,3,3}};

	int days = arr.size();
	vector<vector<int>>memo(days, vector<int>(4, -1));
	cout<<fun(days-1, 3, arr, memo);
}



<<<<<<<<<<<<<<<<<<<-------------------Tabulation------------------>>>>>>>>>>>>>>>>>>>>>>
						O(n*4*3) & O(n*4)

int main(){

	vector<vector<int>>arr = {{1,2,5}, {3,1,1}, {3,3,3}};

	int days = arr.size();
	vector<vector<int>>memo(days, vector<int>(4, 0));
	
	memo[0][0] = max(arr[0][1], arr[0][2]);
	memo[0][1] = max(arr[0][0], arr[0][2]);
	memo[0][2] = max(arr[0][0], arr[0][1]);
	memo[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

	for (int day = 1; day < days; ++day){
		for(int last = 0; last < 4; last++){
			memo[day][last] = 0;
			
			for(int task = 0; task < 3; task++){
				if (task != last){
					int point = arr[day][task] + memo[day-1][task];
					memo[day][last] = max(memo[day][last], point);
				}
			}
		}
	}

	cout<<memo[days-1][3];
}


<<<<<<<<<<<<<<<<<-------------------Space Optimization-------------->>>>>>>>>>>>>>>>>>>>



int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    IOS;
	
	vector<vector<int>>arr = {{1,2,5}, {3,1,1}, {3,3,3}};

	int days = arr.size();
	vector<int>prev(4, 0);
	
	prev[0] = max(arr[0][1], arr[0][2]);
	prev[1] = max(arr[0][0], arr[0][2]);
	prev[2] = max(arr[0][0], arr[0][1]);
	prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

	for (int day = 1; day < days; ++day){
		vector<int>curr(4, 0);
		for(int last = 0; last < 4; last++){
			curr[last] = 0;
			
			for(int task = 0; task < 3; task++){
				if (task != last){
					curr[last] = max(curr[last], arr[day][task] + prev[task]);
				}
			}
		}
		prev = curr;
	}

	cout<<prev[3];
}