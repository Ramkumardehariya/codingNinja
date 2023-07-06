#include <bits/stdc++.h> 
#define MOD 1000000007

int solve(int n){
    if(n==0 || n==1){
        return 1;
    }

    return solve(n-1)+solve(n-2);
}

int solveMem(int n, vector<int> &dp){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = (solveMem(n-2, dp) + solveMem(n-1, dp))%MOD;
}

int solveTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }
    return dp[n];
}

int solveOptimize(int n){
    int prev2 = 1;
    int prev = 1;

    for(int i = 2; i<=n; i++){
        int curr = (prev2 + prev)%MOD;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}


int countDistinctWays(int nStairs) {
    //  Write your code here.

    // recursion
    // return solve(nStairs);
    
    //memoization
    // vector<int> dp(nStairs+1, -1);
    // return solveMem(nStairs, dp);

    //Tabulation method
    // return solveTab(nStairs);

    //solveOptimize
    return solveOptimize(nStairs);
}
