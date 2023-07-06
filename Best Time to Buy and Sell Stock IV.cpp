#include <bits/stdc++.h> 

int solve(int i, int trans, vector<int> &prices, int n, int k){
    if(i == n || trans == 2*k){
        return 0;
    }

    if(trans % 2 == 0){
        return max( -prices[i] + solve(i+1, trans+1, prices, n, k), solve(i+1, trans, prices, n, k));
    }
    return max( prices[i] + solve(i+1, trans+1, prices, n, k), solve(i+1, trans, prices, n, k));
}

int solveMem(int i, int trans, vector<int> &prices, int n, int k, vector<vector<int>> &dp){
    if(i == n || trans == 2*k){
        return 0;
    }

    if(dp[i][trans] != -1){
        return dp[i][trans];
    }

    if(trans % 2 == 0){
        return dp[i][trans] = max( -prices[i] + solveMem(i+1, trans+1, prices, n, k, dp), solveMem(i+1, trans, prices, n, k, dp));
    }
    return dp[i][trans] = max( prices[i] + solveMem(i+1, trans+1, prices, n, k, dp), solveMem(i+1, trans, prices, n, k, dp));
}

int solveTab(vector<int> &prices, int n, int k){

    vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));


    for(int i = n-1; i>=0; i--){
        for(int trans = 2*k-1; trans>=0; trans--){
            if(trans % 2 == 0){
                dp[i][trans] = max( -prices[i] + dp[i+1][trans+1], dp[i+1][trans]);
            } 
            else {
                dp[i][trans] =
                  max(prices[i] + dp[i+1][trans+1],
                      dp[i+1][trans]);
            }
        }
    }
    return dp[0][0];
}

int spaceOptimize(vector<int> &prices, int n, int k){

    vector<int> after(2*k+1, 0);
    vector<int> curr(2*k+1, 0);



    for(int i = n-1; i>=0; i--){
        for(int trans = 2*k-1; trans>=0; trans--){
            if(trans % 2 == 0){
                curr[trans] = max( -prices[i] + after[trans+1], after[trans]);
            } 
            else {
                curr[trans] =
                  max(prices[i] + after[trans+1],
                      after[trans]);
            }
        }
        after = curr;
    }
    return after[0];
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    //recursion
    // return solve(0, 0, prices, n, k);

    //Memoization
    // vector<vector<int>> dp(n, vector<int> (2*k, -1));
    // return solveMem(0, 0, prices, n, k, dp);

    //Tabulation
    // return solveTab(prices, n, k);

    //spaceOptimize
    return spaceOptimize(prices, n, k);
}
