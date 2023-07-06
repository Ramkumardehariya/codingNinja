
int solve(int index, int n, vector<int> &price){
	if(index == 0){
		return n*price[0];
	}

	int notTake = 0 + solve(index-1, n, price);

	int take = INT_MIN;

	int rodLength = index+1;

	if(rodLength <= n){
		take = price[index] + solve(index, n-rodLength, price);
	}

	return max(take, notTake);
}

int solveMem(int index, int n, vector<int> &price, vector<vector<int>> &dp){
	if(index == 0){
		return n*price[0];
	}

	if(dp[index][n] != -1){
		return dp[index][n];
	}

	int notTake = 0 + solveMem(index-1, n, price, dp);

	int take = INT_MIN;

	int rodLength = index+1;

	if(rodLength <= n){
		take = price[index] + solveMem(index, n-rodLength, price, dp);
	}

	return dp[index][n] = max(take, notTake);
}

int solveTab(vector<int> &price, int N){

	vector<vector<int>> dp(N, vector<int>(N+1, 0));

	for(int i = 0; i<=N; i++){
		dp[0][i] = price[0] * i;
	}

    for(int index = 1; index<N; index++){
		for(int n = 0; n<=N; n++){

				int notTake = 0 + dp[index-1][n];

				int take = INT_MIN;

				int rodLength = index+1;

				if(rodLength <= n){
					take = price[index] + dp[index][n-rodLength];
				}

				dp[index][n] = max(take, notTake);
		}
	
	}
	return dp[N-1][N];
}

int spaceOptimize(vector<int> &price, int N){

	vector<int> prev(N+1,0), curr(N+1, 0);

	for(int i = 0; i<=N; i++){
		prev[i] = price[0] * i;
	}

    for(int index = 1; index<N; index++){
		for(int n = 0; n<=N; n++){

				int notTake = 0 + prev[n];

				int take = INT_MIN;

				int rodLength = index+1;

				if(rodLength <= n){
					take = price[index] + curr[n-rodLength];
				}

				curr[n] = max(take, notTake);
		}
		prev = curr;
	
	}
	return prev[N];
}

int spaceOptimize2(vector<int> &price, int N){

	vector<int> curr(N+1, 0);

	for(int i = 0; i<=N; i++){
		curr[i] = price[0] * i;
	}

    for(int index = 1; index<N; index++){
		for(int n = 0; n<=N; n++){

				int notTake = 0 + curr[n];

				int take = INT_MIN;

				int rodLength = index+1;

				if(rodLength <= n){
					take = price[index] + curr[n-rodLength];
				}

				curr[n] = max(take, notTake);
		}
	}
	return curr[N];
}

int cutRod(vector<int> &price, int n)
{
	//recursion
	// return solve(n-1, n, price);

	//Memoiation
	// vector<vector<int>> dp(n, vector<int>(n+1, -1));
	// return solveMem(n-1, n, price, dp);

	//Tabulation
	// return solveTab(price, n);

	//spaceOptimize
	// return spaceOptimize(price, n);

	//spaceOptimize2
	return spaceOptimize2(price, n);
}
