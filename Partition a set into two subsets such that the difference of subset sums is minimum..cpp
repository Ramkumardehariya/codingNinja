#include <bits/stdc++.h> 

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;

	for(int i = 0; i<n; i++){
		totalSum += arr[i];
	}

	int k = totalSum;

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
    // return dp[n-1][k];

	int mini = 1e9;

	for(int s1 = 0; s1<=k/2; s1++){
		if(dp[n-1][s1] == true){
			mini = min(mini, abs((k-s1) - s1));
		}
	}

	return mini;
}
