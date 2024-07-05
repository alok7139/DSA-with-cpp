/*
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.



You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.



Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.
*/

int f(int ind, int tar, vector<int> &profit, vector<int> &weight, vector<vector<int>>&dp){
    if(ind==0){
        return (tar/weight[0]*profit[0]);
    }
    if(dp[ind][tar]!=-1){
        return dp[ind][tar];
    }

    int notpick = f(ind-1,tar,profit,weight,dp);
    int pick = -1e9;
    if(weight[ind]<=tar){
        pick = f(ind,tar-weight[ind],profit,weight,dp)+profit[ind];
    }
    return dp[ind][tar]= max(notpick,pick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    // vector<vector<int>>dp(n,vector<int>(w+1,-1));
    // return f(n-1,w,profit,weight,dp);

    //tabulation
     vector<vector<int>>dp(n,vector<int>(w+1,0));
     for(int i=weight[0];i<=w;i++){
         dp[0][i]=(i/weight[0]*profit[0]);
     }
     for(int i=1;i<n;i++){
         for(int j=0;j<=w;j++){
             int notpick = dp[i-1][j];
             int pick = -1e9;
             if(weight[i]<=j){
                 pick = dp[i][j-weight[i]]+profit[i];
             }
             dp[i][j]=max(pick,notpick);
         }
     }
     return dp[n-1][w];

}