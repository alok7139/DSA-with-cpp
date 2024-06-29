/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int x) {
        int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    // return f(num,n-1,x,dp);
    int ans= f(coins,n-1,x,dp);
    if(ans==1e9){
        return -1;
    }
    else{
        return ans;
    }

        
    }
    int f(vector<int> &num, int ind,int tar,vector<vector<int>>&dp){
    if(ind==0){
        if(tar%num[0]==0){
            return tar/num[0];
        }
        else{
            return 1e9;
        }
    }
    if(dp[ind][tar]!=-1){
        return dp[ind][tar];
    }

    int notpick = 0 + f(num,ind-1,tar,dp);
    int pick = 1e9;
    if(num[ind]<=tar){
        pick = 1+f(num,ind,tar-num[ind],dp);
    }
    return dp[ind][tar]=   min(notpick,pick);
}
};