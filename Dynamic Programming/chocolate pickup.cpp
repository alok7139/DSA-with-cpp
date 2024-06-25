/*
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

Example:
Input: ‘R’ = 3, ‘C’ = 4
       ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
Output: 21

Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.

Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.

Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.
*/

#include <bits/stdc++.h> 
int f(int i,int alice,int bob,int row,int col,vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
    // memoization  tc O(r*c*c)
    if(alice<0 or alice>=col or bob>=col or bob<0){
        return -1e9;
    }
    if(i==row-1){
        if(alice==bob){
            return grid[i][alice];   // because they were in the same position so we add once 
        }
        else{
            return grid[i][alice]+grid[i][bob];
        }
    }
    if(dp[i][alice][bob]!=-1){
        return dp[i][alice][bob];
    }
    int maxi=INT_MIN;
    for(int dj1=-1;dj1<=1;dj1++){  // for alice path should we -1,0,1
        for(int dj2=-1;dj2<=1;dj2++){    // for bob path should we -1,0,1
           int ans;
           if(alice == bob){
               ans = grid[i][alice]+f(i+1,alice+dj1,bob+dj2,row,col,grid,dp);
           }
           else{
               ans = grid[i][alice]+grid[i][bob]+f(i+1,alice+dj1,bob+dj2,row,col,grid,dp);
           }
           maxi=max(maxi,ans);
        }
    }
    return dp[i][alice][bob]=   maxi;

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
   return f(0,0,c-1,r,c,grid,dp);
   //tabulation
   // fill the last row in dp
//    for(int j1=0;j1<c;j1++){  // for alice
//        for(int j2=0;j2<c;j2++){   // for bob
//            if(j1==j2){
//                dp[r-1][j1][j2]=grid[r-1][j1];
//            }
//            else{
//                dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
//            }
//        }
//    }
//    // get to last 2 row
//    for(int i=r-2;i>=0;i--){
//        for(int j1=0;j1<c;j1++){
//            for(int j2=0;j2<c;j2++){
//                int maxi=INT_MIN;
//                for(int dj1=-1;dj1<=1;dj1++){
//                    for(int dj2=-1;dj2<=1;dj2++){
//                        int ans;
//                        if(j1==j2){
//                            ans = grid[i][j1];
//                        }
//                        else{
//                            ans = grid[i][j1]+grid[i][j2];
//                        }
//                        if(j1+dj1<0 or j1+dj1>=c or j2+dj2>=c or j2+dj2<0){
//                            ans += -1e9;
//                        }
//                        else{
//                            ans += dp[i+1][j1+dj1][j2+dj2];
//                        }
//                        maxi=max(maxi,ans);
//                    }
//                }
//                dp[i][j1][j2]=maxi;
//            }
//        }
//    }
//    return dp[0][0][c-1];





}