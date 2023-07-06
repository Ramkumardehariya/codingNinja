#include <bits/stdc++.h> 

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
            curr[sum] = (notTake+take);
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
int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}
