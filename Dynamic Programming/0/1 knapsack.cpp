/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*/

#include <bits/stdc++.h> 
int f(vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>>&dp){
	if(n<0 or maxWeight==0){
		return 0;
	}
	if(dp[n][maxWeight]!=-1){
		return dp[n][maxWeight];
	}
	int notpick = f(weight,value,n-1,maxWeight,dp);
	int pick =INT_MIN;
	if(weight[n]<=maxWeight){
		pick =  value[n]+ f(weight,value,n-1,maxWeight-weight[n],dp);
	}
	return  dp[n][maxWeight]=   max(notpick,pick);
	
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));

	return f(weight,value,n-1,maxWeight,dp);
	//tabulation
	// vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	// for(int i=weight[0];i<=maxWeight;i++){
	// 	dp[0][i]=value[0];
	// }
	// for(int i=1;i<n;i++){
	// 	for(int j=0;j<=maxWeight;j++){
	// 		int notpick = dp[i-1][j];
	// 		int taken = INT_MIN;
	// 		if(weight[i]<=j){
	// 			taken = value[i] + dp[i-1][j-weight[i]];
	// 		}
	// 		dp[i][j]=max(taken,notpick);
	// 	}
	// }
	// return dp[n-1][maxWeight];
}