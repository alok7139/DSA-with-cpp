/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 
*/


class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum += arr[i];
    }
    if((totalsum-target)<0)return 0;
    if((totalsum-target)%2==1) return  0;
    int sum = (totalsum-target)/2;
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    return f(n-1,sum,arr,dp);
        
    }
    int f(int ind, int target, vector<int>& arr,vector<vector<int>>&dp){
    if(ind==0){
       if(target==0 and arr[0]==0) return 2;
       if(target ==0 or arr[0]==target)return 1;
        else return 0;
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }


    int notpick = f(ind-1,target,arr,dp);
    int pick = 0;
    if(arr[ind]<=target){
        pick = f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]=  pick + notpick;
}
};