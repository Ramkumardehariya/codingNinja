#include <bits/stdc++.h> 

int solve(int i, int j, string &t, string &s){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }

    if(t[i] == s[j]){
        return solve(i-1, j-1, t, s) + solve(i-1, j, t, s);
    }

    return solve(i-1, j, t, s);
}

int solveMem(int i, int j, string &t, string &s, vector<vector<int>> &dp){
    if(j==0){
        return 1;
    }
    if(i==0){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(t[i-1] == s[j-1]){
        return dp[i][j] = solveMem(i-1, j-1, t, s, dp) + solveMem(i-1, j, t, s, dp);
    }

    return dp[i][j] = solveMem(i-1, j, t, s, dp);
}

int solveTab(string &t, string &s,int n, int m){

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int j = 1; j<=m; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(t[i-1] == s[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int spaceOptimize(string &t, string &s,int n, int m){

    vector<int> prev(m+1, 0), curr(m+1, 0);

    prev[0] = curr[0] = 1;
    

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(t[i-1] == s[j-1]){
                curr[j] = prev[j-1] + prev[j];
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return curr[m];
}

int spaceOptimize2(string &t, string &s,int n, int m){

    vector<int> prev(m+1, 0);

    prev[0] = 1;
    
    for(int i = 1; i<=n; i++){
        for(int j = m; j>=0; j--){
            if(t[i-1] == s[j-1]){
                prev[j] = prev[j-1] + prev[j];
            }
        }
    }
    return prev[m];
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    //recursion
    // return solve(lt-1, ls-1, t, s);

    //Memoiation
    // vector<vector<int>> dp(lt+1, vector<int> (ls+1, -1));
    // return solveMem(lt, ls, t, s, dp);

    //Tabulation
    // return solveTab(t, s, lt, ls);

    //spaceOptimize
    // return spaceOptimize(t, s, lt, ls);

    //spaceOptimize
    return spaceOptimize2(t, s, lt, ls);
} 
