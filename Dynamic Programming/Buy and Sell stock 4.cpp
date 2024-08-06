/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,0,k,dp);
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