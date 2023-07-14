#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &dp, int n){
    if(n<=1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = solve(dp, n-1) + solve(dp, n-2);
}

int solveTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<n+1; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }

    return dp[n];
}

int solveSpace(int n){

    int prev2 = 1;
    int prev1 = 1;
    int curr = 0;

    for(int i = 2; i<n; i++){
        curr = prev1+ prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
   int n;
   cin>>n;
//    vector<int> dp(n+1);

//    for(int i = 0; i<=n+1; i++){
//        dp[i] =  -1;
//    }
  //Memoization
//    cout<<solve(dp,n-1);

     //Tabulation
//   cout<<solveTab(n-1);

    //space Optimize
    cout<<solveSpace(n);
}
