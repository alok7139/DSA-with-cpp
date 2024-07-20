/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int n=prices.size();
    int trans=2;
    // 3 isliye liye hai trans ya to 0 bar hogi ya 1 bar hogi ya 2 bar hogi 
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(prices,0,0,trans,n,dp);

    // tabulation
    // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // for(int i=n-1;i>=0;i--){
    //     for(int buy=0;buy<=1;buy++){
    //         for(int trans=1;trans<=2;trans++){
    //            if(buy==0){
    //                dp[i][buy][trans]=max(-prices[i]+dp[i+1][1][trans],dp[i+1][0][trans]);
    //            }
    //            else{
    //                dp[i][buy][trans]=max(prices[i]+dp[i+1][0][trans-1],dp[i+1][1][trans]);
    //            }
    //         }
    //     }
    // }
    // return dp[0][0][2];
        
    }
    int f(vector<int>& prices,int ind,int buy,int trans, int n,vector<vector<vector<int>>>&dp){
        if(ind>=n or trans==0) return 0;

        if(dp[ind][buy][trans]!=-1) return dp[ind][buy][trans];

        int profit=0;
        if(!buy){
            profit = max(-prices[ind]+f(prices,ind+1,1,trans,n,dp) , f(prices,ind+1,buy,trans,n,dp));
        } 
        else{
            profit = max(prices[ind]+f(prices,ind+1,0,trans-1,n,dp) , f(prices,ind+1,buy,trans,n,dp));
        }
        return dp[ind][buy][trans]=profit;

    }
};