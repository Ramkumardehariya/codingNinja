#include <bits/stdc++.h> 

int solve(vector<vector<int>> &matrix, int i, int j){
    if(j<0 || j>= matrix[0].size()){
        return -1e9;
    }
    if(i==0){
        return matrix[0][j];
    }

    int up = matrix[i][j] + solve(matrix, i-1, j);
    int leftDiagonal = matrix[i][j] + solve(matrix, i-1, j-1);
    int rightDiagonal = matrix[i][j] + solve(matrix, i-1, j+1);

    return max(up, max(leftDiagonal,rightDiagonal));
}


int solveMem(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp){
    if(j<0 || j>= matrix[0].size()){
        return -1e9;
    }
    if(i==0){
        return matrix[0][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = matrix[i][j] + solveMem(matrix, i-1, j, dp);
    int leftDiagonal = matrix[i][j] + solveMem(matrix, i-1, j-1, dp);
    int rightDiagonal = matrix[i][j] + solveMem(matrix, i-1, j+1,dp);

    return dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
}

int solveTab(vector<vector<int>> &matrix){

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j = 0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){

            int up = matrix[i][j] + dp[i-1][j];

            int leftDiagonal = matrix[i][j];
            if(j-1 >= 0){
                leftDiagonal += dp[i-1][j-1];
            }
            else{
                leftDiagonal += -1e9;
            }
            int rightDiagonal = matrix[i][j];
            if(j+1 < m){
                rightDiagonal +=  dp[i-1][j+1];
            }
            else{
                rightDiagonal += -1e9;
            }

            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
        }
    }
    int maxi = -1e9;
    for(int j= 0; j<m; j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}

int spaceOptimize(vector<vector<int>> &matrix){

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m,0), curr(m, 0);

    for(int j = 0; j<m; j++){
        prev[j] = matrix[0][j];
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){

            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if(j-1 >= 0){
                leftDiagonal += prev[j-1];
            }
            else{
                leftDiagonal += -1e9;
            }
            int rightDiagonal = matrix[i][j];
            if(j+1 < m){
                rightDiagonal +=  prev[j+1];
            }
            else{
                rightDiagonal += -1e9;
            }

            curr[j] = max(up, max(leftDiagonal,rightDiagonal));
        }
        prev = curr;
    }
    int maxi = -1e9;
    for(int j= 0; j<m; j++){
        maxi = max(maxi,prev[j]);
    }
    return maxi;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();


    //recursion
    // int maxi = -1e8;
    // for(int j= 0; j<m; j++){
    //     maxi = max(maxi, solve(matrix, n-1, j));
    // }
    // return maxi;

    //Memoization
    // vector<vector<int>> dp(n, vector<int> (m, -1));
    // int maxi = -1e8;
    // for(int j= 0; j<m; j++){
    //     maxi = max(maxi, solveMem(matrix, n-1, j,dp));
    // }
    // return maxi;

    //Tabulation
    // return solveTab(matrix);

    //spaceOptimize
    return spaceOptimize(matrix);
}
