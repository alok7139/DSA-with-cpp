/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // int maxi=INT_MAX;
        // for(int j=0;j<m;j++){
        //     int ans=f(matrix,n-1,j,m,dp);
        //     maxi=min(maxi,ans);
        // }
        // return maxi;

        // tabulation
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j]+dp[i-1][j];

                int leftdiagonal = matrix[i][j];
                if(j-1>=0){
                    leftdiagonal += dp[i-1][j-1];
                }
                else{
                    leftdiagonal += 1e9;
                }

                int rightdiagonal = matrix[i][j];
                if(j+1<m){
                    rightdiagonal += dp[i-1][j+1];
                }
                else{
                    rightdiagonal += 1e9;
                }

                dp[i][j]=min(up,min(leftdiagonal,rightdiagonal));
            }
        }
        int mini = INT_MAX;
        for(int j=0;j<m;j++){
            mini = min(mini,dp[n-1][j]);
        }
        return mini;
        
    }
    int f(vector<vector<int>> &matrix,int row,int col,int m,vector<vector<int>>&dp){
      // tabulation
      


    // memoization
    if(col<0 or col>=m){
        return 1e9;
    }
    if(row==0){
        return matrix[row][col];
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    
    int up = matrix[row][col]+ f(matrix,row-1,col,m,dp);
    int diagonal_left = matrix[row][col] + f(matrix,row-1,col-1,m,dp);
    int diagonal_right= matrix[row][col]+f(matrix,row-1,col+1,m,dp);
    return  dp[row][col]=  min(up,min(diagonal_left,diagonal_right));
}
};