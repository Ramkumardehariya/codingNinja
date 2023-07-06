#include "bits/stdc++.h"

long solve(int i, long *values, int n, int buy){
    if(i == n){
        return 0;
    }

    long profit = 0;

    if(buy){
        profit = max(-values[i]+solve(i+1, values, n, 0), 0+solve(i+1, values, n, 1));
    }
    else{
        profit = max(values[i]+solve(i+1, values, n, 1), 0+solve(i+1, values, n, 0));
    }

    return profit;
}

long solveMem(int i, long *values, int n, int buy, vector<vector<long>> &dp){
    if(i == n){
        return 0;
    }


    if(dp[i][buy] != -1){
        return dp[i][buy];
    }

    long profit = 0;
    if(buy){
        profit = max(-values[i]+solveMem(i+1, values, n, 0, dp), 0+solveMem(i+1, values, n, 1, dp));
    }
    else{
        profit = max(values[i]+solveMem(i+1, values, n, 1, dp), 0+solveMem(i+1, values, n, 0, dp));
    }

    return dp[i][buy] = profit;
}

long solveTab(long *values, int n){
    vector<vector<long>> dp(n+1, vector<long> (2, 0));

    dp[n][0] = dp[n][1] = 0;

    for(int i = n-1; i>=0; i--){
        for(int buy = 0; buy<=1; buy++){

            long profit = 0;
            if(buy){
                profit = max(-values[i]+dp[i+1][0], 0+dp[i+1][1]);
            }
            else{
                profit = max(values[i]+dp[i+1][1], 0+dp[i+1][0]);
            }

            dp[i][buy] = profit;

        }
    }

    return dp[0][1];
}

long spaceOptimize(long *values, int n){

    vector<long> front(2, 0), curr(2, 0);

    for(int i = n-1; i>=0; i--){
        for(int buy = 0; buy<=1; buy++){

            long profit = 0;
            if(buy){
                profit = max(-values[i]+front[0], 0+front[1]);
            }
            else{
                profit = max(values[i]+front[1], 0+front[0]);
            }

            curr[buy] = profit;

        }
        front = curr;
    }

    return curr[1];
}

long spaceOptimize2(long *values, int n){

    long aheadBuy, currBuy, aheadNotBuy, currNotBuy; 

    aheadBuy = aheadNotBuy = 0;


    for(int i = n-1; i>=0; i--){

        currBuy = max(-values[i]+aheadNotBuy, aheadBuy);
        currNotBuy = max(values[i]+aheadBuy, aheadNotBuy);

        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }

    return aheadBuy;
}


long getMaximumProfit(long *values, int n)
{
    //recursion
    // return solve(0, values, n, 1);

    //Memoiation
    // vector<vector<long>> dp(n, vector<long> (2, -1));
    // return solveMem(0, values, n, 1, dp);

    //Tabulation
    // return solveTab(values, n);

    //spaceOptimize
    // return spaceOptimize(values, n);

    //spaceOptimize
    return spaceOptimize2(values, n);
}
