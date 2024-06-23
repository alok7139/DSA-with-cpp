/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    // return f(grid, n - 1, m - 1,dp);
    return solve(grid,0,0,n,m,dp);

    }
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==n-1 and j==m-1){
            return grid[i][j];
        }
        if(i>=n or j>=m){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = grid[i][j] + solve(grid,i,j+1,n,m,dp);
        int down = grid[i][j]+solve(grid,i+1,j,n,m,dp);
        return dp[i][j]=min(right,down);
    }
    int f(vector<vector<int>> &grid, int row, int col,vector<vector<int>>&dp) {
     //tabulation
      for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            if(i==0 and j==0){
                dp[i][j]=grid[i][j];
            }
            else{
            int top=grid[i][j];
            if(i>0){
                top += dp[i-1][j];
            }
            else{
                top += 1e9;
            }
            int left=grid[i][j];
            if(j>0){
                left += dp[i][j-1];
            } else {
                left += 1e9;
            }
            dp[i][j] = min(top, left);
            }
        }
    }
    return dp[row][col];

        // memoization
    // if (row == 0 and col == 0) {
    //     return grid[row][col];
    // }
    // if (row < 0 or col < 0) {
    //     return 1e9;  
    // }
    // if(dp[row][col]!=-1){
    //     return dp[row][col];
    // }
    // int up = grid[row][col] + f(grid, row - 1, col,dp);
    // int left = grid[row][col] + f(grid, row, col - 1,dp);
    
    // return dp[row][col]=  min(up, left);
}

};