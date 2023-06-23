#include <bits/stdc++.h> 
int mod = 1000000007;

long long solve(int i, int j,bool isTrue, string &exp){
    if(i>j){
        return 0;
    }
    if(i == j){
        if(isTrue){
            return exp[i] == 'T';
        }
        else{
            return exp[i] == 'F';
        }
    }

    long long ways = 0;

    for(int ind = i+1; ind<=j-1; ind += 2){

        long long lf = solve(i, ind-1, 0, exp)%mod;
        long long lt = solve(i, ind-1, 1, exp)%mod;
        long long rf = solve(ind+1, j, 0, exp)%mod;
        long long rt = solve(ind+1, j, 1, exp)%mod;

        if(exp[ind] == '&'){
            if(isTrue){
                ways = (ways + (lt*rt)%mod)%mod;
            }
            else{
                ways = (ways+ (lt*rf)%mod + (lf*rf)%mod + (lf*rt)%mod)%mod;
            }
        }
        else if(exp[ind] == '|'){

            if(isTrue){
                ways = (ways+ (lt*rf)%mod + (lt*rt)%mod + (lf*rt)%mod)%mod;
            }
            else{
                ways = (ways + (lf*rf)%mod)%mod;
            }
        }
        else{
            if(isTrue){
                ways = (ways + (lf*rt)%mod + (lt*rf)%mod)%mod;
            }
            else{
                ways = (ways + (lf*rf)%mod + (lt*rt)%mod)%mod;
            }
        }

    }
    return ways;
}


long long solveMem(int i, int j,bool isTrue, string &exp, vector<vector<vector<long long>>> &dp){
    if(i>j){
        return 0;
    }
    if(i == j){
        if(isTrue){
            return exp[i] == 'T';
        }
        else{
            return exp[i] == 'F';
        }
    }

    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    long long ways = 0;

    for(int ind = i+1; ind<=j-1; ind += 2){

        long long lf = solveMem(i, ind-1, 0, exp, dp)%mod;
        long long lt = solveMem(i, ind-1, 1, exp, dp)%mod;
        long long rf = solveMem(ind+1, j, 0, exp, dp)%mod;
        long long rt = solveMem(ind+1, j, 1, exp, dp)%mod;

        if(exp[ind] == '&'){
            if(isTrue){
                ways = (ways + (lt*rt)%mod)%mod;
            }
            else{
                ways = (ways+ (lt*rf)%mod + (lf*rf)%mod + (lf*rt)%mod)%mod;
            }
        }
        else if(exp[ind] == '|'){

            if(isTrue){
                ways = (ways+ (lt*rf)%mod + (lt*rt)%mod + (lf*rt)%mod)%mod;
            }
            else{
                ways = (ways + (lf*rf)%mod)%mod;
            }
        }
        else{
            if(isTrue){
                ways = (ways + (lf*rt)%mod + (lt*rf)%mod)%mod;
            }
            else{
                ways = (ways + (lf*rf)%mod + (lt*rt)%mod)%mod;
            }
        }

    }
    return dp[i][j][isTrue] = ways;
}


int evaluateExp(string & exp) {

    int n = exp.size();
    //recursion
    // return solve(0, n-1, 1, exp);

    //Memoization
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (n, vector<long long> (2, -1)));
    return solveMem(0, n-1, 1, exp, dp);
}
