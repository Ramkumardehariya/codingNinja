
#include "bits/stdc++.h"

long solve(int index, int tar, int *arr){
    if(index == 0){
        return (tar%arr[index] == 0);
    }

    long notTake = solve(index-1, tar, arr);
    long take = 0;

    if(arr[index] <= tar){
        take = solve(index, tar-arr[index],arr);
    }

    return notTake+take;
}

long solveMem(int index, int tar, int *arr, vector<vector<long>> &dp){
    if(index == 0){
        return (tar%arr[index] == 0);
    }

    if(dp[index][tar] != -1){
        return dp[index][tar];
    }

    long notTake = solveMem(index-1, tar, arr, dp);
    long take = 0;

    if(arr[index] <= tar){
        take = solveMem(index, tar-arr[index],arr, dp);
    }

    return dp[index][tar] = notTake+take;
}

long solveTab(int *arr, int n, int value){
    vector<vector<long>> dp(n, vector<long> (value+1, 0));

    for(int T = 0; T<=value; T++){
        dp[0][T] = (T%arr[0] == 0);
    }

    for(int index = 1; index<n; index++){
        for(int tar = 0; tar<=value; tar++){

            long notTake = dp[index-1][tar];
            long take = 0;

            if(arr[index] <= tar){
                take = dp[index][tar-arr[index]];
            }

            dp[index][tar] = notTake+take;
        }
    }
    return dp[n-1][value];
}

long spaceOptimize(int *arr, int n, int value){
    vector<long> prev(value+1, 0), curr(value+1, 0);

    for(int T = 0; T<=value; T++){
        prev[T] = (T%arr[0] == 0);
    }

    for(int index = 1; index<n; index++){
        for(int tar = 0; tar<=value; tar++){

            long notTake = prev[tar];
            long take = 0;

            if(arr[index] <= tar){
                take = curr[tar-arr[index]];
            }

            curr[tar] = notTake+take;
        }
        prev = curr;
    }
    return prev[value];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //recursion
    // return solve(n-1, value,denominations);

    //memoization
    // vector<vector<long>> dp(n, vector<long> (value+1, -1));
    // return solveMem(n-1, value, denominations, dp);

    //solveTab
    // return solveTab(denominations, n, value);

    //spaceOptimize
    return spaceOptimize(denominations, n, value);
}
