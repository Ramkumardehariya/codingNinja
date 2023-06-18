#include <bits/stdc++.h> 

int solve(int i, int j, vector<vector<int>> &grid){
    if(i == 0 && j == 0){
        return grid[0][0];
    }
    if( i < 0 || j < 0){
        return 1e9;
    }

    int up = grid[i][j] + solve(i-1, j, grid);
    int left = grid[i][j] + solve(i, j-1, grid);

    return min(up,left);
}

int solveMem(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i == 0 && j == 0){
        return grid[0][0];
    }
    if( i < 0 || j < 0){
        return 1e9;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = grid[i][j] + solveMem(i-1, j, grid, dp);
    int left = grid[i][j] + solveMem(i, j-1, grid, dp);

    return dp[i][j] = min(up,left);
}

int solveTab(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];

    for(int i = 0; i<n; i++){
        for(int j= 0; j<m; j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }
            else{
                int left = grid[i][j];
                int up = grid[i][j];
                if(i>0){
                    up += dp[i-1][j];
                }
                else{
                    up += 1e9;
                }

                if(j>0){
                    left += dp[i][j-1];
                }
                else{
                    left += 1e9;
                }
                dp[i][j] = min(left,up);
            }
        }
    }
    return dp[n-1][m-1];
}

int spaceOptimize(int n, int m, vector<vector<int>> &grid){

    vector<int> prev(m, 0);


    for(int i = 0; i<n; i++){
        vector<int> curr(m, 0);
        for(int j= 0; j<m; j++){
            if(i == 0 && j == 0){
                curr[j] = grid[i][j];
            }
            else{
                int left = grid[i][j];
                int up = grid[i][j];
                if(i>0){
                    up += prev[j];
                }
                else{
                    up += 1e9;
                }

                if(j>0){
                    left += curr[j-1];
                }
                else{
                    left += 1e9;
                }
                curr[j] = min(left,up);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();

    //recursion
    // return solve(n-1, m-1, grid);

    //memoization
    // vector<vector<int>> dp(n, vector<int> (m, -1));
    // return solveMem(n-1, m-1, grid, dp);

    //Tabulation
    // return solveTab(n, m, grid);

    //optimization
    return spaceOptimize(n, m, grid);
}
