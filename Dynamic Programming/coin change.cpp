/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(coins,n-1,amount,dp);

        // tabulation
        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // for(int i=0;i<=amount;i++){
        //     if(i%coins[0]==0){
        //         dp[0][i]=1;
        //     }
        // }
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<=amount;j++){
        //         int notpick = dp[i-1][j];
        //         int pick =0;
        //         if(coins[i]<=j){
        //             pick = dp[i][j-coins[i]];
        //         }
        //         dp[i][j]=pick + notpick;
        //     }
        // }
        // return dp[n-1][amount];
        
    }
    int f(vector<int>& denominations, int ind, int tar,vector<vector<int>>&dp){
     if(ind==0){
         return (tar%denominations[0]==0) ? 1:0;
     }
     if(dp[ind][tar]!=-1){
         return dp[ind][tar];
     }

    int notpick = f(denominations,ind-1,tar,dp);
    int pick = 0 ;
    if (denominations[ind] <= tar) {
       pick = f(denominations, ind, tar - denominations[ind],dp);
    }
    return  dp[ind][tar]=  pick + notpick;
}
};