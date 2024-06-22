/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row= obstacleGrid.size();
        int col = obstacleGrid[0].size();
       vector<vector<int>>dp(row,vector<int>(col,-1));
        
        // return f(obstacleGrid,row-1,col-1,dp);
        return solve(obstacleGrid,0,0,row,col,dp);
        
    }
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,int row,int col,vector<vector<int>>&dp){
        if(i<row and j<col and obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==row-1 and j==col-1){
            return 1;
        }
        
        if(i>=row or j>=col){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = solve(obstacleGrid,i,j+1,row,col,dp);
        int down = solve(obstacleGrid,i+1,j,row,col,dp);
        return dp[i][j]=right+down;
    }
    int f(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>>&dp){
        //tabulation
        int mod=1000000007;
    for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            if(i>=0 and j>=0 and obstacleGrid[i][j]==1){
                dp[i][j]=0;
                continue;
            }
            if(i==0 and j==0){
                dp[i][j]=1;
                continue;
            }
            
            int up=0,left=0;
            if(i>0){
                up = dp[i-1][j];
            }
            if(j>0){
                left=dp[i][j-1];
            }
            dp[i][j]=(up+left);
        }
    }
    return dp[row][col];


        //memoization
        //   if(row>=0 and col>=0 and obstacleGrid[row][col]==1){
        //       return 0;
        //   }
        //   if(row==0 and col==0){
        //       return 1;
        //   }
        //   if(row<0 or col<0){
        //       return 0;
        //   }
        //   if(dp[row][col]!=-1){
        //       return dp[row][col];
        //   }
        //   int up=f(obstacleGrid,row-1,col,dp);
        //   int left = f(obstacleGrid,row,col-1,dp);
        //   return dp[row][col]= up+left;
    }
};