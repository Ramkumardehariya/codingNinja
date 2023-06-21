#include "bits/stdc++.h"

int solve(int index1 , int index2, string s1, string s2, int count){

	if(index1 == 0 || index2 == 0){
		return count;
	}

	int ans = count;

	if(s1[index1-1] == s2[index2-1]){
		ans =  solve(index1-1, index2-1, s1, s2, count+1);
	}

	int diff2 = solve(index1, index2-1, s1, s2, 0);
	int diff = solve(index1-1, index2, s1, s2, 0);
	
	return max(ans, max(diff, diff2));
}

int solveMem(int index1 , int index2, string s1, string s2,int count,vector<vector<vector<int>>> &dp){

	if(index1 == 0 || index2 == 0){
		return count;
	}

	if(dp[index1][index2][count] != -1){
		return dp[index1][index2][count];
	}

	int ans = count;

	if(s1[index1-1] == s2[index2-1]){
		ans =  solveMem(index1-1, index2-1, s1, s2, count+1, dp);
	}

	int diff2 = solveMem(index1, index2-1, s1, s2, 0, dp);
	int diff = solveMem(index1-1, index2, s1, s2, 0, dp);
	
	return dp[index1][index2][count] = max(ans, max(diff, diff2));

}

int solveTab(string s1, string s2){
	int n = s1.length();
	int m = s2.length();

	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));


	int ans = 0;

	for(int index1 = 1; index1<=n; index1++){
		for(int index2 = 0; index2<=m; index2++){
			
			if(s1[index1-1] == s2[index2-1]){
				dp[index1][index2] = 1 + dp[index1-1][index2-1];
				ans = max(ans, dp[index1][index2]);
			}
			else{
			    dp[index1][index2] = 0;
			} 
		}
	}
	return ans;
}


int spaceOptimize(string s1, string s2){
	int n = s1.length();
	int m = s2.length();

	vector<int> curr(m+1, 0), prev(m+1, 0);
	int ans = 0;

	for(int index1 = 1; index1<=n; index1++){
		for(int index2 = 0; index2<=m; index2++){
			
			if(s1[index1-1] == s2[index2-1]){
				curr[index2] = 1 + prev[index2-1];
				ans = max(ans, curr[index2]);
			}
			else{
			    curr[index2] = 0;
			} 
		}
		prev = curr;
	}
	return ans;
} 
int lcs(string &str1, string &str2){
	
	int n = str1.length();
	int m = str2.length();

	//recursion
	// return solve(n, m, str1, str2, 0);

	//memoiation
	// vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (n+1, -1)));
	// return solveMem(n, m, str1, str2, 0, dp);

	//Tabulation
	// return solveTab(str1, str2);

	//spaceOptimization
	return spaceOptimize(str1, str2);
}
