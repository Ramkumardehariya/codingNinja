#include <bits/stdc++.h> 

int solve(vector<int> &weight, vector<int> &value, int index, int Wcapacity){
	if(index == 0){
		if(weight[index] <= Wcapacity){
			return value[index];
		}
		else{
			return 0;
		}
	}

	int include = 0;

	if(weight[index] <= Wcapacity){
		include = value[index] + solve(weight,value,index-1,Wcapacity-weight[index]);
	}

	int exclude = 0 + solve(weight,value,index-1,Wcapacity);

	return max(include,exclude);
}



int solveMemo(vector<int> &weight, vector<int> &value,vector<vector<int>> &dp, int index, int Wcapacity){
	if(index == 0){
		if(weight[index] <= Wcapacity){
			return value[index];
		}
		else{
			return 0;
		}
	}

	if(dp[index][Wcapacity] != -1){
		return dp[index][Wcapacity];
	}

	int include = 0;
	if(weight[index] <= Wcapacity){
		include = value[index] + solveMemo(weight,value,dp,index-1,Wcapacity-weight[index]);
	}

	int exclude = 0 + solveMemo(weight,value,dp,index-1,Wcapacity);

	dp[index][Wcapacity] = max(include,exclude);
	return dp[index][Wcapacity];
}

int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight){

	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));

	for(int w=weight[0]; w<=maxWeight; w++){
		if(weight[0] <= maxWeight){
			dp[0][w] =value[0];
		}
	}

	for(int index = 1; index<n; index++){
		for(int w=0; w<=maxWeight; w++){

			int incl = 0;
			if(weight[index] <= w){
				incl = value[index] + dp[index-1][w-weight[index]];
			}
			int excl = 0 + dp[index-1][w];
			dp[index][w] = max(incl,excl);
		}
	}

	return dp[n-1][maxWeight];
}

int solveOptimize(vector<int> &weight,vector<int> &value, int n, int maxWeight){
	
	vector<int> prev(maxWeight+1,0);
	vector<int> curr(maxWeight+1,0);

	for(int w=weight[0]; w<=maxWeight; w++){
		if(weight[0] < maxWeight){
			prev[w] = value[0];
		}
		else{
			prev[w] = 0;
		}
	}

	for(int index = 1; index<n; index++){
		for(int w=0; w<=maxWeight; w++){
			int incl = 0;
			if(weight[index] <= w){
				incl = value[index] + prev[w-weight[index]];
			}
			int excl = 0 + prev[w];
			curr[w] = max(incl,excl);
		}
		prev = curr;
	}
	return prev[maxWeight];
}


int solve2Optimize(vector<int> &weight,vector<int> &value, int n, int maxWeight){
	
	
	vector<int> curr(maxWeight+1,0);

	for(int w=weight[0]; w<=maxWeight; w++){
		if(weight[0] < maxWeight){
			curr[w] = value[0];
		}
		else{
			curr[w] = 0;
		}
	}

	for(int index = 1; index<n; index++){
		for(int w=maxWeight; w>=0; w--){
			int incl = 0;
			if(weight[index] <= w){
				incl = value[index] + curr[w-weight[index]];
			}
			int excl = 0 + curr[w];
			curr[w] = max(incl,excl);
		}
		
	}
	return curr[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	//recursive aproach
	// return solve(weight,value,n-1,maxWeight);

    //using Top down aproach = recursive + memoization 
	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	// return solveMemo(weight,value,dp,n-1,maxWeight);


	//using Bottom Up aproach = Tabulization aproach
	// return solveTab(weight,value,n,maxWeight);

	//space Optimize method
	// return solveOptimize(weight,value,n,maxWeight);

	//second space ooptimize method;
	return solve2Optimize(weight,value,n,maxWeight);

}
