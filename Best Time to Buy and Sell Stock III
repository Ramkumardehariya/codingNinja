#include <bits/stdc++.h> 


int solve(int i, vector<int>& prices,int buy, int cap, int n){
    if(cap == 0){
        return 0;
    }
    if(i == n){
        return 0;
    }

    if(buy == 1){
        return max(-prices[i] + solve(i+1, prices, 0, cap, n), 0 + solve(i+1, prices, 1, cap, n));
    }
    
    return max(prices[i] + solve(i+1, prices, 1, cap-1, n), solve(i+1, prices, 0, cap, n));
}

int solveMem(int i, vector<int>& prices,int buy, int cap, int n, vector<vector<vector<int>>> &dp){
    if(cap == 0){
        return 0;
    }
    if(i == n){
        return 0;
    }

    if(dp[i][buy][cap] != -1){
        return dp[i][buy][cap];
    }
    if(buy == 1){
        return dp[i][buy][cap] = max(-prices[i] + solveMem(i+1, prices, 0, cap, n, dp), 0 + solveMem(i+1, prices, 1, cap, n, dp));
    }
    
    return dp[i][buy][cap] = max(prices[i] + solveMem(i+1, prices, 1, cap-1, n, dp), solveMem(i+1, prices, 0, cap, n, dp));
}

int solveTab(vector<int>& prices, int n){

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

    for(int i = n-1; i>=0; i--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap = 1; cap<=2; cap++){
                
                    int profit = 0;
                    if(buy == 1){
                        profit = 
                        max(-prices[i] + dp[i+1][0][cap], 0 + dp[i+1][1][cap]);
                    } 
                    else {
                    profit =
                        max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
    }
    
    return dp[0][1][2];
}

int spaceOptimze(vector<int>& prices, int n){

    vector<vector<int>> after(2, vector<int> (3, 0));
    vector<vector<int>> curr(2, vector<int> (3, 0));


    for(int i = n-1; i>=0; i--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap = 1; cap<=2; cap++){
                
                    int profit = 0;
                    if(buy == 1){
                        profit = 
                        max(-prices[i] + after[0][cap], 0 + after[1][cap]);
                    } 
                    else {
                    profit =
                        max(prices[i] + after[1][cap - 1], after[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            after = curr;
    }
    
    return after[1][2];
}


int spaceOptimize2(int i, int trans, int n, vector<int>& prices, vector<vector<int>> &dp){
    if(trans == 4){
        return 0;
    }
    if(i == n){
        return 0;
    }

    if(dp[i][trans] != -1){
        return dp[i][trans];
    }
    if(trans % 2 == 0){
        return dp[i][trans] = max(-prices[i] + spaceOptimize2(i+1, trans+1, n, prices, dp),0 + spaceOptimize2(i+1, trans, n, prices, dp));
    }
    return dp[i][trans] = max(prices[i] + spaceOptimize2(i+1, trans+1, n, prices, dp),0 + spaceOptimize2(i+1, trans, n, prices, dp));
}

int maxProfit(vector<int>& prices, int n)
{
    //recursion
    // return solve(0, prices,1, 2, n);

    //Memoizatin
    // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    // return solveMem(0, prices, 1, 2, n, dp);

    //Tabulation
    // return solveTab(prices, n);

    //spaceOptimize
    // return spaceOptimze(prices, n);

    //spaceOptimze2
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return spaceOptimize2(0, 0, n, prices, dp);
}
