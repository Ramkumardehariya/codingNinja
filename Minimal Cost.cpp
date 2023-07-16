#include<bits/stdc++.h>

int solve(int i, int k , vector<int> &height){
    if(i == 0){
        return 0;
    }

    int miniSteps = INT_MAX;
    for(int j = 1; j<=k; j++){
        int steps;
        if(i-j >= 0){
            steps = abs(height[i]-height[i-j])+ solve(i-j, k, height);
        }

        miniSteps = min(miniSteps, steps);
    }
    return miniSteps;
}

int solveMem(int i, int k , vector<int> &height, vector<int> &dp){
    if(i == 0){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    int miniSteps = INT_MAX;
    for(int j = 1; j<=k; j++){
        int steps;
        if(i-j >= 0){
            steps = abs(height[i]-height[i-j])+ solveMem(i-j, k, height,dp);
        }

        miniSteps = min(miniSteps, steps);
    }
    dp[i] = miniSteps;

    return dp[i];
}

int solveTab(int n, int k , vector<int> &height){
    vector<int> dp(n, 0);

    for(int i = 1; i<n; i++){
        
        int miniSteps = INT_MAX;
        for(int j = 1; j<=k; j++){
            int steps;
            if(i-j >= 0){
                steps = abs(height[i]-height[i-j])+ dp[i-j];
            }

            miniSteps = min(miniSteps, steps);
        }
        dp[i] = miniSteps;
    }
    return dp[n-1];
}


int solveTab(int n, int k , vector<int> &height){
    vector<int> dp(n, 0);

    for(int i = 1; i<n; i++){
        
        int miniSteps = INT_MAX;
        for(int j = 1; j<=k; j++){
            int steps;
            if(i-j >= 0){
                steps = abs(height[i]-height[i-j])+ dp[i-j];
            }

            miniSteps = min(miniSteps, steps);
        }
        dp[i] = miniSteps;
    }
    return dp[n-1];
}

int minimizeCost(int n, int k, vector<int> &height){

    //recursion
    // return solve(n-1, k, height, dp);

    //solveMem
    // vector<int> dp(n, -1);
    // return solveMem(n-1, k, height, dp);

    //solveTab
    return solveTab(n, k, height);
}
