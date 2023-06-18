#include <bits/stdc++.h> 


int solve(int n, vector<int> &heights){
    if(n == 0){
        return 0;
    }

    int left = solve(n-1, heights) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n>1)
      right = solve(n-2, heights) + abs(heights[n]-heights[n-2]);

    return min(left,right);
}

int solveMem(int n, vector<int> &heights,vector<int> &dp){
    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int left = solveMem(n-1, heights,dp) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n>1)
      right = solveMem(n-2, heights, dp) + abs(heights[n]-heights[n-2]);

    return dp[n] = min(left,right);
}

int solveTab(int n, vector<int> &heights){
    vector<int> dp(n+1, 0);
    dp[0] = 0;

    for(int i = 1; i<n; i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);

        int right= INT_MAX;
        if(i>1)
           right = dp[i-2] + abs(heights[i]-heights[i-2]);

        dp[i] = min(right, left);
    }

    return dp[n-1];
}

int spaceOptimize(int n, vector<int> &heights){
    
    int prev2 = 0;
    int prev = 0;

    for(int i = 1; i<n; i++){
        int left = prev + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1)
           right = prev2 + abs(heights[i]-heights[i-2]);

        int curr = min(left,right);

        prev2 = prev;
        prev = curr;
        
    }

    return prev;
}

int frogJump(int n, vector<int> &heights)
{
    //recursion
    // return solve(n-1, heights);

    //Memoization
    // vector<int> dp(n+1, -1);
    // return solveMem(n-1, heights, dp);

    //Tabulatio
    // return solveTab(n, heights);

    //spaceOptimize
    return spaceOptimize(n, heights);
}
