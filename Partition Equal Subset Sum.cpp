bool solve(int index, int target, vector<int> &arr){
    if(target == 0){
        return true;
    }
    if(index == 0){
        return (arr[0]==target);
    }

    bool notTake = solve(index-1, target, arr);

    bool take = false;
    if(target >= arr[index]){
        take = solve(index -1, target-arr[index], arr);
    }

    return take || notTake;
}

bool solveMem(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0){
        return true;
    }
    if(index == 0){
        return (arr[0]==target);
    }

    if(dp[index][target] != -1){
        return dp[index][target];
    }

    bool notTake = solveMem(index-1, target, arr,dp);

    bool take = false;

    if(target >= arr[index]){
        take = solveMem(index -1, target-arr[index], arr, dp);
    }

    return dp[index][target] = take || notTake;
}

bool solveTab(int n, int k, vector<int> &arr){

    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));

    for(int i = 0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for(int index = 1; index <n; index++){
        for(int target = 1; target<=k; target++){

            bool notTake = dp[index-1][target];

            bool take = false;

            if(target >= arr[index]){
                take = dp[index-1][target-arr[index]];
            }

            dp[index][target] = take || notTake;
        }
    }
    return dp[n-1][k];
}

bool spaceOptimize(int n, int k, vector<int> &arr){

    vector<bool> prev(k+1, 0), curr(k+1, 0);

    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for(int index = 1; index <n; index++){
        for(int target = 1; target<=k; target++){

            bool notTake = prev[target];

            bool take = false;

            if(target >= arr[index]){
                take = prev[target-arr[index]];
            }

            curr[target] = take || notTake;
        }
        prev = curr;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
	int totalSum = 0;
	for(int i = 0; i<n; i++){
		totalSum += arr[i];
	}

	if(totalSum % 2){
		return false;
	}

	int target = totalSum/2;

	//recursion
	// return solve(n, target, arr);

	//Memoization
	// vector<vector<int>> dp(n, vector<int> (target+1, -1));
	// return solveMem(n-1, target, arr, dp);

	//Tabulation
	// return solveTab(n, target, arr);

	//spaceOptimize
	return solveTab(n, target, arr);
}
