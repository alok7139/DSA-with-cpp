/*
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.



Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.



Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.



Example:
Input: 'arr' = [1, 1, 4, 5]

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.
*/

#include <bits/stdc++.h>
int f(int ind,int k,vector<int>&arr,vector<vector<int>>&dp){
	int mod=1000000007;
	// case for 0 1 0 0 and 1 1 0 0 and 1 0 0 0
	if(ind==0){
      if(k==0 and arr[0]==0) return 2;
      if(k==0 or arr[0]==k) return 1;
      return 0;
  }
    // if(k==0) return 1;
	// if(ind==0){
	// 	return (arr[ind] == k) ? 1:0;
	// }
	if(dp[ind][k]!=-1){
		return dp[ind][k];
	}
	int notpick = f(ind-1,k,arr,dp);
	int pick=0;
	if(arr[ind]<=k){
		pick = f(ind-1,k-arr[ind],arr,dp);
	}
	return dp[ind][k]=   (notpick+pick)%mod;


}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return f(n-1,k,arr,dp);
	//tabulation
	// vector<vector<int>>dp(n,vector<int>(k+1,0));

	// int mod=1000000007;
	// for(int i=0;i<n;i++){
	// 	dp[i][0]=1;
	// }
	// if(arr[0]<=k){
	// 	dp[0][arr[0]]=1;
	// }
	// for(int i=1;i<n;i++){
	// 	for(int j=1;j<=k;j++){
	// 		int notpick = dp[i-1][j];
	// 		int pick =0;
	// 		if(arr[i]<=j){
	// 			pick = dp[i-1][j-arr[i]];
	// 		}
	// 		dp[i][j]= (pick + notpick)%mod;
	// 	}
	// }
	// return (dp[n-1][k])%mod;

}
