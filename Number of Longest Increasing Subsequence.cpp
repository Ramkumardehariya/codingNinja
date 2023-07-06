#include <bits/stdc++.h> 
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();

    vector<int> dp(n, 1), count(n, 1);
    
    int maxi = 1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j] && 1+dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
                count[i] = count[j];
            }
            else if(arr[i] > arr[j] && 1+dp[j] == dp[i]){
                count[i] += count[j];
            }
        }

        maxi = max(maxi, dp[i]);
    }

    int num = 0;

    for(int i= 0; i<n; i++){
        if(dp[i] == maxi){
            num += count[i];
        }
    }
    return num;
}
