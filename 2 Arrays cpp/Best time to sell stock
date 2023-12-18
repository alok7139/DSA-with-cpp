/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/
int maxProfit(vector<int>& prices) {
        //brute force
        // int maxi=0;
        // int n=prices.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(prices[j]>prices[i]){
        //             maxi = max(maxi,prices[j]-prices[i]);
        //         }
        //     }
        // }
        // return maxi;
        
         // optimal sol
         int maxi=INT_MAX;
         int profit=0;
         for(int i=0;i<prices.size();i++){
             if(prices[i] < maxi){
                 maxi=prices[i];
             }
             int overall = prices[i]-maxi; // overall profit in a day
             if(overall > profit){
                 profit = overall;
             }

         }
         return profit;

        
        
    }
