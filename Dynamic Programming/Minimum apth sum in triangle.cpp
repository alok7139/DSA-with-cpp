/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(triangle,n,0,0,dp);
        
    }
    int f(vector<vector<int>>& triangle,int n,int i,int j,vector<vector<int>>&dp){

        //tabulation
    //       for(int i=0;i<n;i++){
	// 	dp[n-1][i]=triangle[n-1][i];
	// }
	// for(int i=n-2;i>=0;i--){
	// 	for(int j=i;j>=0;j--){
	// 		int down=triangle[i][j]+dp[i+1][j];
	// 		int diagonal=triangle[i][j]+dp[i+1][j+1];

	// 		dp[i][j]=min(down,diagonal);
	// 	}
	// }
	// return dp[i][j];

        // memoization
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = triangle[i][j]+ f(triangle,n,i+1,j,dp);
        int diagonal = triangle[i][j]+ f(triangle,n,i+1,j+1,dp);
        return dp[i][j]= min(down,diagonal);

    }
};