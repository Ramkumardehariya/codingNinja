#include <bits/stdc++.h> 

int solve(int i, int j1,int j2,int n, int m, vector<vector<int>> &grid){

    if(j1 < 0 ||j2 < 0 || j1>=m || j2 >= m){
        return -1e8;
    }
    if(i == n-1){
        if(j1 == j2){
            return grid[i][j2];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }

    int maxi = -1e8;
    for(int jd1 = -1; jd1<=1; jd1++){
        for(int jd2 = -1; jd2<=1; jd2++){
            int value = 0;
            if(j1 == j2){
                value = grid[i][j1];
            }
            else{
                value = grid[i][j1]+grid[i][j2];
            }
            
            value += solve(i+1, j1+jd1, j2+jd2, n, m, grid);

            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int solveMem(int i, int j1,int j2,int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(j1 < 0 ||j2 < 0 || j1>=m || j2 >= m){
        return -1e8;
    }
    if(i == n-1){
        if(j1 == j2){
            return grid[i][j2];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }

    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    int maxi = -1e8;
    for(int jd1 = -1; jd1<=1; jd1++){
        for(int jd2 = -1; jd2<=1; jd2++){
            int value = 0;
            if(j1 == j2){
                value = grid[i][j1];
            }
            else{
                value = grid[i][j1]+grid[i][j2];
            }
            
            value += solveMem(i+1, j1+jd1, j2+jd2, n, m, grid, dp);

            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int solveTab(int n, int m, vector<vector<int>> &grid){

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, 0)));

    for(int j1 = 0; j1<m; j1++){
        for(int j2= 0; j2<m; j2++){
            if(j1 == j2){
               dp[n-1][j1][j2] = grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    for(int i = n-2; i>=0; i--){
        for(int j1 = 0; j1<m; j1++){
            for(int j2 = 0; j2<m; j2++){

                int maxi = -1e9;
                for(int jd1 = -1; jd1<=1; jd1++){
                    for(int jd2 = -1; jd2<=1; jd2++){
                        int value = 0;
                        if(j1 == j2){
                            value = grid[i][j1];
                        }
                        else{
                            value = grid[i][j1]+grid[i][j2];
                        }
                        
                        if(j1+jd1 >= 0 && j1+jd1 < m && j2+jd2 >= 0 && j2+jd2 < m){
                            value += dp[i+1][j1+jd1][j2+jd2];
                        }
                        else{
                            value += -1e9;
                        }

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}

int spaceOptimize(int n, int m, vector<vector<int>> &grid){

    vector<vector<int>> front(m, vector<int> (m, 0));
    vector<vector<int>> curr(m, vector<int> (m, 0));

    for(int j1 = 0; j1<m; j1++){
        for(int j2= 0; j2<m; j2++){
            if(j1 == j2){
               front[j1][j2] = grid[n-1][j1];
            }
            else{
                front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    for(int i = n-2; i>=0; i--){
        for(int j1 = 0; j1<m; j1++){
            for(int j2 = 0; j2<m; j2++){

                int maxi = -1e9;
                for(int jd1 = -1; jd1<=1; jd1++){
                    for(int jd2 = -1; jd2<=1; jd2++){
                        int value = 0;
                        if(j1 == j2){
                            value = grid[i][j1];
                        }
                        else{
                            value = grid[i][j1]+grid[i][j2];
                        }
                        
                        if(j1+jd1 >= 0 && j1+jd1 < m && j2+jd2 >= 0 && j2+jd2 < m){
                            value += front[j1+jd1][j2+jd2];
                        }
                        else{
                            value += -1e9;
                        }

                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][m-1];
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    //recursion
    // return solve(0, 0, m-1,n, m, grid);

    //Memoizatiion
    // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
    // return solveMem(0, 0, m-1, n, m, grid, dp);

    //Tabulation
    // return solveTab(n, m, grid);

    //spaceOptimize
    return spaceOptimize(n, m, grid);
}
