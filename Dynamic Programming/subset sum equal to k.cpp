/*
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
*/


#include <bits/stdc++.h> 
bool f(int ind ,int k,vector<int> &arr,vector<vector<int>> &dp){
    // memoization
    if(k==0){
        return true;
    }
    if(ind==0){
        return arr[0] == k;
    }
    if(dp[ind][k]!=-1){
        return dp[ind][k];
    }
    bool notpick = f(ind-1,k,arr,dp);
    bool pick = false;
    if(arr[ind]<=k){
        pick = f(ind-1,k-arr[ind],arr,dp);
    }
    return dp[ind][k]= notpick || pick;

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
//    return f(n-1,k,arr,dp);
//tabulation
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));

for(int i=0;i<n;i++){
    dp[i][0]=true;  // for all the target 0 in k pos
}
dp[0][arr[0]]=true;
for(int i=1;i<n;i++){
    for(int tar=1;tar<=k;tar++){
        bool notpick = dp[i-1][tar];
        bool pick=false;
        if(arr[i]<=tar){
            pick = dp[i-1][tar-arr[i]];
        }
        dp[i][tar]=notpick || pick;
    }
}
return dp[n-1][k];

}