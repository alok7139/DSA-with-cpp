/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<int>>dp(n,vector<int>(2,-1));
         return f(prices,0,0,n,dp);
        
    }
    int f(vector<int>& prices, int ind,int buy,int n,vector<vector<int>>&dp){
        if(ind>=n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit=0;
        if(!buy){
            profit = max(-prices[ind]+f(prices,ind+1,1,n,dp) , f(prices,ind+1,buy,n,dp));
        } 
        else{
            profit = max(prices[ind]+f(prices,ind+1,0,n,dp) , f(prices,ind+1,buy,n,dp));
        }
        return dp[ind][buy]=profit;
    }
};