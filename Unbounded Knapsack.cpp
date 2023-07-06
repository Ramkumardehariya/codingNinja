#include <bits/stdc++.h> 

int solve(int index, int w, vector<int> &profit, vector<int> &weight){

    if(index == 0){
        return ((int)w/weight[index]) * profit[index];
    }

    int nonTake = 0 + solve(index-1, w, profit, weight);

    int take = INT_MIN;

    if(weight[index] <= w){
        take = profit[index] + solve(index, w-weight[index],profit,weight);
    }

    return max(nonTake, take);
}

int solveMem(int index, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){

    if(index == 0){
        return ((int)w/weight[index]) * profit[index];
    }

    if(dp[index][w] != -1){
        return dp[index][w];
    }

    int nonTake = 0 + solveMem(index-1, w, profit, weight, dp);

    int take = INT_MIN;

    if(weight[index] <= w){
        take = profit[index] + solveMem(index, w-weight[index],profit,weight, dp);
    }

    return dp[index][w] = max(nonTake, take);
}

int solveTab(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<vector<int>> dp(n, vector<int> (w+1, 0));

    for(int W= 0; W<=w; W++){
        dp[0][W] = ((int)W/weight[0]) * profit[0];
    }

    for(int index = 1; index<n; index++){
        for(int W = 0; W<=w; W++){

            int nonTake = 0 + dp[index-1][W];

            int take = INT_MIN;

            if(weight[index] <= W){
                take = profit[index] + dp[index][W-weight[index]];
            }

            dp[index][W] = max(nonTake, take);
        }
    }

    return dp[n-1][w];
}

int spaceOptimize(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int> curr(w+1,0), prev(w+1, 0);


    for(int W= 0; W<=w; W++){
        prev[W] = ((int)W/weight[0]) * profit[0];
    }

    for(int index = 1; index<n; index++){
        for(int W = 0; W<=w; W++){

            int nonTake = 0 + prev[W];

            int take = INT_MIN;

            if(weight[index] <= W){
                take = profit[index] + curr[W-weight[index]];
            }

            curr[W] = max(nonTake, take);
        }
        prev =curr;
    }
    return prev[w];
}

int spaceOptimize2(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int> prev(w+1, 0);


    for(int W= 0; W<=w; W++){
        prev[W] = ((int)W/weight[0]) * profit[0];
    }

    for(int index = 1; index<n; index++){
        for(int W = 0; W<=w; W++){

            int nonTake = 0 + prev[W];

            int take = INT_MIN;

            if(weight[index] <= W){
                take = profit[index] + prev[W-weight[index]];
            }

            prev[W] = max(nonTake, take);
        }
    }
    return prev[w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    //recursion
    // return solve(n-1, w, profit, weight);

    //memoization
    // vector<vector<int>> dp(n, vector<int> (w+1, -1));
    // return solveMem(n-1, w, profit, weight, dp);

    //solveTab
    // return solveTab(n, w, profit, weight);

    //spaceOptimize
    // return spaceOptimize(n, w, profit, weight);

    //spceOptimizesecond
    return spaceOptimize2(n, w, profit, weight);
}
