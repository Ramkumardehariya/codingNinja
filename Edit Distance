

int solve(int i, int j, string s1, string s2){
    if(i < 0){
        return j+1;
    }
    if(j < 0){
        return i+1;
    }

    if(s1[i] == s2[j]){
        return solve(i-1, j-1, s1, s2);
    }

    return 1 + min(solve(i-1, j, s1, s2), 
           min(solve(i, j-1, s1, s2), 
           solve(i-1,j-1,s1, s2)));
}


int solveMem(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    if(i == 0){
        return j;
    }
    if(j == 0){
        return i;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i-1] == s2[j-1]){
        return solveMem(i-1, j-1, s1, s2, dp);
    }

    return 1 + min(solveMem(i-1, j, s1, s2, dp), 
           min(solveMem(i, j-1, s1, s2, dp), 
           solveMem(i-1,j-1,s1, s2, dp)));
}

int solveTab(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 0; i<=n; i++){
        dp[i][0] = i;
    }

    for(int j = 0; j<=m; j++){
        dp[0][j] = j;
    }

    for(int i= 1; i<=n; i++){
        for(int j = 1;j<=m; j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] =  1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }

        }
    }
    return dp[n][m];
}

int spaceOptimize(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int j = 0; j<=m; j++){
        prev[j] = j;
    }

    for(int i= 1; i<=n; i++){
        curr[0] = i;
        for(int j = 1;j<=m; j++){

            if(s1[i-1] == s2[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                curr[j] =  1 + min(prev[j-1], min(prev[j], curr[j-1]));
            }

        }
        prev = curr;
    }
    return prev[m];
}


int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    //recursion
    //return solve(n-1, m-1, str1, str2);

    //Memoiation
    // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // return solveMem(n, m, str1, str2, dp);

    //Tabulation
    // return solveTab(str1, str2);

    //spaceOptimize
    return spaceOptimize(str1, str2);
}
