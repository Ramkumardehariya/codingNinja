#include "bits/stdc++.h"

bool solve(int i, int j, string pattern, string text){

   if(i<0 && j<0){
      return true;
   }
   if(i<0 && j>=0){
      return false;
   }

   if(i>=0 && j<0){
      for(int k = 0; k<=i; k++){
         if(pattern[k] != '*'){
            return false;
         }
      }
      return true;
   }

   if(pattern[i] == text[j] || pattern[i]=='?'){
      return solve(i-1, j-1, pattern, text);
   }

   if(pattern[i] == '*'){
      return solve(i-1, j, pattern, text) | solve(i, j-1, pattern, text);
   } 

   return false;
}

bool solveMem(int i, int j, string pattern, string text, vector<vector<int>> &dp){

   if(i==0 && j==0){
      return true;
   }
   if(i==0 && j>0){
      return false;
   }

   if(i>0 && j==0){
      for(int k = 1; k<=i; k++){
         if(pattern[k-1] != '*'){
            return false;
         }
      }
      return true;
   }

   if(dp[i][j] != -1){
      return dp[i][j];
   }

   if(pattern[i-1] == text[j-1] || pattern[i-1]=='?'){
      return dp[i][j] = solveMem(i-1, j-1, pattern, text, dp);
   }
   else if(pattern[i-1] == '*'){
      return dp[i][j] = (solveMem(i-1, j, pattern, text, dp) || solveMem(i, j-1, pattern, text, dp));
   } 
   else{
      return false;
   }
}


bool solveTab(string str, string pattern){
        vector<vector<int>> dp(str.length()+1, vector<int> (pattern.length()+1, 0));

        dp[0][0] = true;

        for(int j = 1; j<=pattern.length(); j++){
            bool flag = true;
            for(int k = 1; k<=j; k++){
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i = 1; i<=str.length(); i++){
            for(int j = 1; j<=pattern.length(); j++){
                if(pattern[j-1] == str[i-1] || pattern[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[str.length()][pattern.length()];
    }

bool wildcardMatching(string pattern, string text)
{
   //recursion
   // int n = pattern.size();
   // int m = text.size();
   // return solve(n-1, m-1, pattern, text);

   //Memoiation
   // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
   // return solveMem(n, m, pattern, text, dp);

   //Tabulation
   return solveTab(text, pattern);
}
