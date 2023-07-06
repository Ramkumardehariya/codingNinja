#include "bits/stdc++.h"

int solve(int index1 , int index2, string s1, string s2){

	if(index1 < 0 || index2 < 0){
		return 0;
	}

	if(s1[index1] == s2[index2]){
		return 1 + solve(index1-1, index2-1, s1, s2);
	}

	return max(solve(index1-1, index2, s1, s2),solve(index1, index2-1, s1, s2));
}

int solveMem(int index1 , int index2, string s1, string s2,vector<vector<int>> &dp){

	if(index1 < 0 || index2 < 0){
		return 0;
	}

	if(dp[index1][index2] != -1){
		return dp[index1][index2];
	}

	if(s1[index1] == s2[index2]){
		return 1 + solveMem(index1-1, index2-1, s1, s2, dp);
	}

	return dp[index1][index2] = max(solveMem(index1-1, index2, s1, s2, dp),solveMem(index1, index2-1, s1, s2, dp));
}

int solveMem2(int index1 , int index2, string s1, string s2,vector<vector<int>> &dp){

	if(index1 == 0 || index2 == 0){
		return 0;
	}

	if(dp[index1][index2] != -1){
		return dp[index1][index2];
	}

	if(s1[index1] == s2[index2]){
		return 1 + solveMem(index1-1, index2-1, s1, s2, dp);
	}

	return dp[index1][index2] = max(solveMem(index1-1, index2, s1, s2, dp),solveMem(index1, index2-1, s1, s2, dp));
}

int solveTab(string s1, string s2){
	int n = s1.length();
	int m = s2.length();

	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

	for(int i = 0; i<=n; i++){
		dp[i][0] = 0;
	}
	for(int i = 0; i<=m; i++){
		dp[0][i] = 0;
	}

	for(int index1 = 1; index1<=n; index1++){
		for(int index2 = 0; index2<=m; index2++){
			
			if(s1[index1-1] == s2[index2-1]){
				dp[index1][index2] = 1 + dp[index1-1][index2-1];
			}
			else{
			    dp[index1][index2] = max(dp[index1-1][index2],dp[index1][index2-1]);
			} 
		}
	}
	return dp[n][m];
}


int spaceOptimize(string s1, string s2){
	int n = s1.length();
	int m = s2.length();

	vector<int> curr(m+1, 0), prev(m+1, 0);

	for(int i = 0; i<=m; i++){
		prev[i] = 0;
	}

	for(int index1 = 1; index1<=n; index1++){
		for(int index2 = 0; index2<=m; index2++){
			
			if(s1[index1-1] == s2[index2-1]){
				curr[index2] = 1 + prev[index2-1];
			}
			else{
			    curr[index2] = max(prev[index2],curr[index2-1]);
			} 
		}
		prev = curr;
	}
	return curr[m];
}

int lcs(string s, string t)
{
	//recursion
	int n = s.length();
	int m = t.length();
	// return solve(n-1, m-1, s, t);

	//memoiation
	// vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
	// return solveMem(n-1, m-1, s, t, dp);
	// return solveMem2(n-1, m-1, s, t, dp);

	//Tabulation
	// return solveTab(s, t);

	//spaceOptimize
	return spaceOptimize(s, t);
}
