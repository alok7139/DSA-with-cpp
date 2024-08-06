/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
    int solve(vector<int>&prices,int ind,int buy, vector<vector<int>>&dp){
        if(ind>=prices.size())return 0;

        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        int ans=0;
        if(buy==0){
          ans = max(-prices[ind]+solve(prices,ind+1,!buy,dp) , solve(prices,ind+1,buy,dp));
        }
        else{
            ans = max(prices[ind]+solve(prices,ind+2,!buy,dp),solve(prices,ind+1,buy,dp));
        }

        return dp[ind][buy] = ans;
    }
};