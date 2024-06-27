/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int totalsum=0;
	for(int i=0;i<n;i++){
		totalsum += arr[i];
	}
	if(totalsum%2!=0){
		return false;
	}
	int target = totalsum/2;
	vector<vector<int>>dp(n,vector<int>(target+1,-1));
	return f(n-1,target,arr,dp);
    //tabulation
//     vector<vector<bool>>dp(n,vector<bool>(target+1,0));
//     for(int i=0;i<n;i++){
//         dp[i][0]=true;
//     }
//     if (arr[0] <= target) {
//     dp[0][arr[0]] = true;
// }
//     for(int i=1;i<n;i++){
//         for(int tar=1;tar<=target;tar++){
//             bool notpick = dp[i-1][tar];
//             bool pick = false;
//             if(tar>=arr[i]){
//                 pick = dp[i-1][tar-arr[i]];
//             }
//             dp[i][tar]= notpick || pick;
//         }
//     }
//     return dp[n-1][target];
        
    }
    bool f(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp){
	// memoization
	if(tar==0){
		return true;
	}
	if(ind==0){
		return arr[ind]==tar;
	}
	if(dp[ind][tar]!=-1){
		return dp[ind][tar];
	}
	bool notpick = f(ind-1,tar,arr,dp);
	bool pick =false;
	if(arr[ind]<=tar){
		pick = f(ind-1,tar-arr[ind],arr,dp);
	}
	return  dp[ind][tar]=  notpick || pick;
}

};