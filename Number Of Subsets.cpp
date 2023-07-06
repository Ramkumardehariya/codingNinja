#include <bits/stdc++.h> 

int solve(int index, int sum, vector<int> &num){
    if(sum == 0){
        return 1;
    }
    if(index == 0){
        return (num[0] == sum);
    }

    int notTake = solve(index-1, sum, num);

    int take = 0;
    if(sum >= num[index]){
        take = solve(index-1, sum-num[index], num);
    }

    return take+notTake;
}

int solveMem(int index, int sum, vector<int> &num, vector<vector<int>> &dp){
    if(sum == 0){
        return 1;
    }
    if(index == 0){
        return num[0] == sum;
    }

    if(dp[index][sum] != -1){
        return dp[index][sum];
    }

    int notTake = solveMem(index-1, sum, num, dp);

    int take = 0;
    if(sum >= num[index]){
        take = solveMem(index-1, sum-num[index], num, dp);
    }

    return dp[index][sum] = notTake+take;
}

int solveTab(vector<int> &num, int tar, int n){

    vector<vector<int>> dp(n, vector<int> (tar+1, 0));

    for(int i = 0; i<n; i++){
        dp[i][0] = 1;
    }
    if(tar>= num[0]){
        dp[0][num[0]] = 1;
    }

    for(int index = 1; index<n; index++){
        for(int sum = 0; sum<=tar; sum++){

            int notTake = dp[index-1][sum];

            int take = 0;
            if(sum >= num[index]){
                take = dp[index-1][sum-num[index]];
            }

            dp[index][sum] = notTake+take;
        }
    }
    return dp[n-1][tar];
}

int spaceOptimize(vector<int> &num, int tar, int n){

    vector<int> prev(tar+1, 0), curr(tar+1, 0);

    prev[0] = curr[0] = 1;

    if (tar >= num[0]) {
      prev[num[0]] = 1;
    }

    for(int index = 1; index<n; index++){
        for(int sum = 0; sum<=tar; sum++){

            int notTake = prev[sum];

            int take = 0;
            if(sum >= num[index]){
                take = prev[sum-num[index]];
            }

            curr[sum] = notTake+take;
        }
        prev = curr;
    }
    return prev[tar];
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    //recursion
    // return solve(n-1, tar, num);

    // vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    // return solveMem(n-1, tar, num, dp);

    //Tabulation
    // return solveTab(num, tar, n);

    //spaceOptimize
    return spaceOptimize(num, tar, n);
}
