#include <algorithm> 
#include <iostream>
#include <vector>

int solve(int i, int prev_ind, int arr[], int n){
    if(i == n){
        return 0;
    }

    int take = 0 + solve(i+1, i, arr, n);
    int notTake = 0;

    if(prev_ind == -1 || arr[i] > arr[prev_ind]){
        notTake = 1 + solve(i+1, i, arr, n);
    }

    return max(take , notTake);
}


int solveMem(int i, int prev_ind, int arr[], int n, vector<vector<int>> &dp){

    if(i == n){
        return 0;
    }

    if(dp[i][prev_ind+1] != -1){
        return dp[i][prev_ind+1];
    }

    int take = 0 + solveMem(i+1, prev_ind, arr, n, dp);
    int notTake = 0;

    if(prev_ind == -1 || arr[i] > arr[prev_ind]){
        notTake = 1 + solveMem(i+1, i, arr, n, dp);
    }

    return dp[i][prev_ind+1] = max(take , notTake);
}


int solveTab(int arr[], int n){

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));


    for(int i = n-1; i>=0; i--){
        for(int prev_ind = i-1; prev_ind>=-1; prev_ind--){

            int take = 0 + dp[i+1][prev_ind+1];
            int notTake = 0;

            if(prev_ind == -1 || arr[i] > arr[prev_ind]){
                notTake = 1 + dp[i+1][i+1];
            }
            dp[i][prev_ind+1] = max(take , notTake);
        }
    }
    return dp[0][-1+1];
}

int spaceOptimize(int arr[], int n){

    vector<int> after(n+1, 0);
    vector<int> curr(n+1, 0);


    for(int i = n-1; i>=0; i--){
        for(int prev_ind = i-1; prev_ind>=-1; prev_ind--){

            int take = 0 + after[prev_ind+1];
            int notTake = 0;

            if(prev_ind == -1 || arr[i] > arr[prev_ind]){
                notTake = 1 + after[i+1];
            }
            curr[prev_ind+1] = max(take , notTake);
        }
        after = curr;
    }
    return curr[-1+1];
    
}

int solve1(int arr[], int n){

    vector<int> dp(n ,1);
    int maxi = 1;

    for(int i = 0; i<n; i++){
        for(int prev_ind = 0; prev_ind < i; prev_ind++){
            if(arr[prev_ind] < arr[i]){
                dp[i] = max(dp[i], 1+dp[prev_ind]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int solve2(int arr[], int n){
    vector<int> temp;
    temp.push_back(arr[0]);

    int len = 1;

    for(int i = 1; i<n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            // std::vector<int>::iterator ind;
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[index]=arr[i];
        }
    }

    return len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    //recursion
    // return solve(0, -1, arr, n);

    // vector<vector<int>> dp(n, vector<int> (n+1, -1));
    // return solveMem(0, -1, arr, n, dp);

    //memoization
    // return solveTab(arr, n);

    // return solve1(arr, n);

    //binary sesarch
    return solve2(arr, n);
}
