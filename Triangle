#include <bits/stdc++.h> 

int solve(vector<vector<int>>& triangle, int n, int i, int j){
	if(i == n-1){
		return triangle[i][j];
	}

	int down = triangle[i][j] + solve(triangle, n, i+1, j);
	int diagonal = triangle[i][j] + solve(triangle, n, i+1, j+1);

	return min(down, diagonal);
}

int solveMem(vector<vector<int>>& triangle, int n, int i, int j, vector<vector<int>> &dp){

	if(i == n-1){
		return triangle[i][j];
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int down = triangle[i][j] + solveMem(triangle, n, i+1, j, dp);
	int diagonal = triangle[i][j] + solveMem(triangle, n, i+1, j+1, dp);

	return dp[i][j] = min(down, diagonal);
}

int solveTab(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int> (n, 0));

	for(int i = 0; i<n; i++){
		dp[n-1][i] = triangle[n-1][i];
	}

	for(int i = n-2; i>=0; i--){
		for(int j = i; j>=0; j--){
			int down = triangle[i][j] + dp[i+1][j];
			int diagonal = triangle[i][j] + dp[i+1][j+1];

			dp[i][j] = min(down,diagonal);
		}
	}
	return dp[0][0];
}

int spaceOptimize(vector<vector<int>>& triangle, int n){
	vector<int> front(n, 0), curr(n, 0);

	for(int i = 0; i<n; i++){
		front[i] = triangle[n-1][i];
	}

	for(int i = n-2; i>=0; i--){
		for(int j = i; j>=0; j--){
			int down = triangle[i][j] + front[j];
			int diagonal = triangle[i][j] + front[j+1];

			curr[j] = min(down,diagonal);
		}
		front = curr;
	}
	return front[0];
}


int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.

	//recursion
	// return solve(triangle, n, 0, 0);

	//Memoization
	// vector<vector<int>> dp(n, vector<int> (n, -1));
	// return solveMem(triangle, n, 0, 0, dp);

	//solveTab
	// return solveTab(triangle, n);

	//spaceOptimize
	return spaceOptimize(triangle, n);
}
