#include <bits/stdc++.h> 

int solve(int i, int j, vector<int> &cuts){
    if(i > j){
        return 0;
    }

    int mini = 1e9;

    for(int ind = i; ind<=j; ind++){
        int cut = cuts[j+1]-cuts[i-1] + solve(i, ind-1, cuts) + solve(ind+1, j, cuts); 
        mini = min(mini, cut);
    }

    return mini;
}

int solveMem(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
    if(i > j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mini = 1e9;

    for(int ind = i; ind<=j; ind++){
        int cost = cuts[j+1]-cuts[i-1] + solveMem(i, ind-1, cuts, dp) + solveMem(ind+1, j, cuts, dp); 
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

int solveTab(int n, int c, vector<int> &cuts){

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

    for(int i = c; i>=1; i--){
        for(int j = 1; j<=c; j++){

            if(i>j){
                continue;
            }

            int mini = 1e9;

            for(int ind = i; ind<=j; ind++){
                int cut = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j]; 
                mini = min(mini, cut);
            }

            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

int cost(int n, int c, vector<int> &cuts){
    // cuts.push_back(n);
    // cuts.insert(cuts.begin(), 0);
    // sort(cuts.begin(), cuts.end());

    //recursion
    // return solve(1, c, cuts);

    //Memoization
    // vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
    // return solveMem(1, c, cuts, dp);

    //Tabulation
    return solveTab(n, c, cuts);
}
