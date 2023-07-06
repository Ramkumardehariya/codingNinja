#include <bits/stdc++.h> 


int solve(int i, int j, vector<int> &arr){
    if(i == j){
        return 0;
    }

    int mini = 1e9;

    for(int k = i; k<j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] +
         solve(i, k, arr) + solve(k+1, j, arr);

        mini = min(mini, steps);
    }

    return mini;
}


int solveMem(int i, int j, vector<int> &arr, vector<vector<int>> &dp){

    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = 1e9;

    for(int k = i; k<j; k++){
        int steps = arr[i-1] * arr[k] * arr[j] +
         solveMem(i, k, arr, dp) + solveMem(k+1, j, arr, dp);

        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int solveTab(vector<int> &arr, int n){
    
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int i = 1; i<n; i++){
        dp[i][i] = 0;
    }

    for(int i = n-1; i>=1; i--){
        for(int j = i+1; j<n; j++){

            int mini = 1e9;
            for(int k = i; k<j; k++){
                int steps = arr[i-1] * arr[k] * arr[j] +
                dp[i][k] + dp[k+1][j];

                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr, int N)
{
    //recursion
    // return solve(1, N-1, arr);

    //Memoization
    // vector<vector<int>> dp(N, vector<int> (N, -1));
    // return solveMem(1, N-1, arr, dp);


    //solveTab
    return solveTab(arr, N);
}
