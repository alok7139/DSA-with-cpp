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
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,0,2,dp);
    }

    int solve(vector<int>& prices,int ind,int buy,int trans,vector<vector<vector<int>>>&dp){
        if(ind >= prices.size() or trans==0)return 0;

        if(dp[ind][buy][trans]!=-1)return dp[ind][buy][trans];
        
        int ans=0;
        if(buy==0){
          ans = max(-prices[ind] + solve(prices,ind+1,!buy,trans,dp) , solve(prices,ind+1,buy,trans,dp));
        }
        else{
            ans = max(prices[ind] + solve(prices,ind+1,!buy,trans-1,dp) , solve(prices,ind+1,buy,trans,dp));
        }

        return dp[ind][buy][trans]=ans;
    }
};