#include <bits/stdc++.h>

int solve(int i , int j){
	if(i== 0 && j == 0){
		return 1;
	}
	if(i<0 || j< 0){
		return 0;
	}

	int up = solve(i-1, j);
	int left = solve(i, j-1);

	return up+left;
}

int solveMem(int i , int j, vector<vector<int>> &dp){

	if(i== 0 && j == 0){
		return 1;
	}
	if(i<0 || j< 0){
		return 0;
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int up = solveMem(i-1, j, dp);
	int left = solveMem(i, j-1, dp);

	return dp[i][j] = up+left;
}

int solveTab(int m, int n){
	vector<vector<int>> dp(m, vector<int> (n, 0));

	dp[0][0] = 1;

	for(int i = 0; i<m; i++){
		for(int j =0; j<n; j++){
			if(i ==0 && j==0){
				dp[i][j] = 1;
			}
			else{
				int up = 0;
				int left = 0;
				if(i>0){
					up = dp[i-1][j];
				}
				if(j>0){
					left = dp[i][j-1];
				}
			    dp[i][j] = up+left;
			}
		}
	}
	return dp[m-1][n-1];
}

int spaceOptimize(int m, int n){
	vector<int> prev(n, 0);

	prev[0] = 1;

	for(int i = 0; i<m; i++){

		vector<int> curr(n, 0);

		for(int j =0; j<n; j++){
			if(i ==0 && j==0){
				curr[j] = 1;
			}
			else{
				int up = 0;
				int left = 0;
				if(i>0){
					up = prev[j];
				}
				if(j>0){
					left = curr[j-1];
				}
			    curr[j] = up+left;
			}
		}
		prev = curr;
	}
	return prev[n-1];
}
int uniquePaths(int m, int n) {
	// Write your code here.

	//recursion
	// return solve(m-1, n-1);

	//Memoization 
	// vector<vector<int>> dp(m, vector<int>(n, -1));
	// return solveMem(m-1, n-1, dp);

	//Tabulatiion
	// return solveTab(m, n);

	//spaceOptimize
	return spaceOptimize(m, n);
}
