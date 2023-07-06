#include <bits/stdc++.h> 

int solve(int n, vector<int> &nums){
    if(n==0){
        return nums[n];
    }
    if(n < 0){
        return 0;
    }

    int take = nums[n] + solve(n-2, nums);
    int nonTake = 0 + solve(n-1, nums);
    
    return max(take, nonTake);
}

int solveMem(int n, vector<int> &nums, vector<int> &dp){
    if(n==0){
        return nums[n];
    }
    if(n < 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    
    int take = nums[n] + solveMem(n-2, nums, dp);
    int nonTake = 0 + solveMem(n-1, nums, dp);
    
    return dp[n] = max(take, nonTake);
}

int solveTab(vector<int> &nums){
    int n = nums.size();
    
    vector<int> dp(n+1, 0);
    dp[0] = nums[0];
    
    for(int i = 1; i<n; i++){
        int take;
        if(i < 0)
            take = 0 + dp[i-2];
        else
            take = nums[i] + dp[i-2];
        
        int nonTake = 0 + dp[i-1];

        dp[i] = max(take,nonTake);
    }
    return dp[n-1];
}

int spaceOptimize(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0];

    for(int i = 1; i<n; i++){
        
        int take = prev2 + nums[i];

        int nonTake = prev + 0;

        int curr = max(take, nonTake);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    
    //recursion
    // int n = nums.size();
    // return solve(n-1,nums);

    //solveMem
    // vector<int> dp(n+1, -1);
    // return solveMem(n-1, nums, dp);

    //solveTab
    // return solveTab(nums);

    //spaceOptimize
    return spaceOptimize(nums);
}
