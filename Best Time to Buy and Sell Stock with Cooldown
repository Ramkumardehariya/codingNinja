#include <bits/stdc++.h> 

    int solve(int i, int buy, vector<int>& prices, int n){

        if(i >= n){
            return 0;
        }

        if(buy == 1){
            return max(-prices[i] + solve(i+1, 0, prices, n), 0 + solve(i+1, 1, prices, n));
        }
        return max(prices[i]+ solve(i+2, 1, prices, n), 0 + solve(i+1, 0, prices, n));
    }

    int solveMem(int i, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){

        if(i >= n){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        if(buy == 1){
            return dp[i][buy] = max(-prices[i] + solveMem(i+1, 0, prices, n, dp), 0 + solveMem(i+1, 1, prices, n, dp));
        }
        return dp[i][buy] = max(prices[i]+ solveMem(i+2, 1, prices, n, dp), 0 + solveMem(i+1, 0, prices, n, dp));

    }

    int solveTab(vector<int> & prices){
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (3, 0));

        for(int i = n-1; i>= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                
                if(buy == 1){
                    dp[i][buy] = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
                }
                else{ 
                    dp[i][buy] = max(prices[i]+ dp[i+2][1], 0 + dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }

    int solveTab1(vector<int> & prices){

        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (3, 0));

        for(int i = n-1; i>= 0; i--){
                
            dp[i][1] = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
                
            dp[i][0] = max(prices[i]+ dp[i+2][1], 0 + dp[i+1][0]);
        }
        return dp[0][1];
    }

    int spaceOptimize(vector<int> & prices){
        int n = prices.size();
        vector<int> front1(3, 0);
        vector<int> front2(3, 0);
        vector<int> curr(3, 0);


        for(int i = n-1; i>= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                
                if(buy == 1){
                    curr[buy] = max(-prices[i] + front1[0], 0 + front1[1]);
                }
                else{ 
                    curr[buy] = max(prices[i]+ front2[1], 0 + front1[0]);
                }

            }
            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }

int stockProfit(vector<int> &prices){
            //recursion
        int n = prices.size();
        // return solve(0, 1, prices, n);

        //memoization
        // vector<vector<int>> dp(n, vector<int> (2, -1));
        // return solveMem(0, 1, prices, n, dp);

        //Tabulation
        // return solveTab(prices);
        // return solveTab1(prices);

        //spaceOptimize
        return spaceOptimize(prices);
}
