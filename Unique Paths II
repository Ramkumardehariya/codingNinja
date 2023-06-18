int MOD = (int)(1e9+7);

int solve(int i, int j, vector< vector< int> > &mat){

    if(i>=0 && j>=0 && mat[i][j] == -1){
        return 0;
    }
    if(i == 0 && j == 0){
        return 1;
    }
    if(i < 0 || j< 0){
        return 0;
    }

    int up = solve(i-1, j, mat);
    int left = solve(i, j-1, mat);

    return (up+left)%MOD;
}

int solveMem(int i, int j, vector< vector< int> > &mat,vector<vector<int>> &dp){

    if(i>=0 && j>=0 && mat[i][j] == -1){
        return 0;
    }
    if(i == 0 && j == 0){
        return 1;
    }
    if(i < 0 || j < 0){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = solveMem(i-1, j, mat, dp);
    int left = solveMem(i, j-1, mat, dp);

    return dp[i][j] = (up+left)%MOD;
}


int solveTab(int n, int m, vector< vector< int> > &mat){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i >= 0 && j>=0 && mat[i][j] == -1){
                dp[i][j] = 0;
            }
            else if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else{
                int left = 0;
                int up = 0;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    left = dp[i][j-1];
                }
                dp[i][j] = (left+up)%MOD;
            }
        }
    }
    return dp[n-1][m-1];
}

int spaceOptimize(int n, int m, vector< vector< int> > &mat){
    vector<int> prev(m, 0);

    for(int i = 0; i<n; i++){
        vector<int> curr(m, 0);
        for(int j = 0; j<m; j++){
            if(i >= 0 && j>=0 && mat[i][j] == -1){
                curr[j] = 0;
            }
            else if(i == 0 && j == 0){
                curr[j] = 1;
            }
            else{
                int left = 0;
                int up = 0;
                if(i>0){
                    up = prev[j];
                }
                if(j>0){
                    left = curr[j-1];
                }
                curr[j] = (left+up)%MOD;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here

    //recursion
    // return solve(n-1, m-1, mat);

    //memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return solveMem(n-1, m-1 , mat, dp);

    //Tabulation
    // return solveTab(n, m, mat);

    //spaceOptimize
    return spaceOptimize(n, m, mat);
}
