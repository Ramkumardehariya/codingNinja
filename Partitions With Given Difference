#include <bits/stdc++.h> 
int MOD = (int)(1e9+7);

int solveMem(int index, int sum, vector<int> &arr, vector<vector<int>> dp){

    if(index == 0){
        if(sum == 0 && arr[0] == 0){
            return 2;
        }
        if(sum == 0 || sum == arr[0]){
            return 1;
        }
        else{
           return 0;
        }
    }

    if(dp[index][sum] != -1){
        return dp[index][sum];
    }

    int notTake = solveMem(index-1, sum, arr, dp);

    int take = 0;
    if(arr[index] <= sum){
        int take = solveMem(index-1, sum-arr[index], arr, dp);
    }

    return dp[index][sum] = (take+notTake)%MOD;
}


int findWays(vector<int> &num, int tar){
    int n = num.size();
    vector<int> prev(tar+1, 0), curr(tar+1, 0);
    if(num[0] == 0){
        prev[0] = 2;
    }
    else{
        prev[0] = 1;
    }

    if(num[0] != 0 && num[0] <= tar){
        prev[num[0]] = 1;
    }

    for(int ind =1; ind<n; ind++){
        for(int sum = 0; sum<=tar; sum++){
            int notTake = prev[sum];
            int take = 0;
            if(num[ind] <= sum){
                take = prev[sum-num[ind]];
            }
            curr[sum] = (notTake+take)%MOD;
        }
        prev = curr;
    }
    return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr){
    int totalSum = 0;
    for(auto &it: arr){
        totalSum += it;
    }

    if(totalSum-d < 0 || (totalSum -d)%2){
        return 0;
    }

    return findWays(arr, (totalSum-d)/2);
}
