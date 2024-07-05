/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
*/

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
          int n = s.size();
    int m = t.size();
    vector<vector<int>> memo(n, vector<int>(m+1, -1)); 
    return f(s, t, n - 1, m - 1, memo);
    // tabulation
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  

    // for(int i=0;i<=n;i++){
    //      dp[i][0]=0;
    // }
    // for(int i=0;i<=m;i++){
    //     dp[0][i]=0;
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s[i-1]==t[j-1]){
    //            dp[i][j]=1+dp[i-1][j-1];
    //         }
    //         else{
    //             dp[i][j]=max( dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    // }
    // return dp[n][m];
        
    }
    int f(string &s, string& t, int ind1, int ind2, vector<vector<int>>& memo) {
    if (ind1 < 0 || ind2 < 0) {
        return 0;
    }
    if (memo[ind1][ind2] != -1) {
        return memo[ind1][ind2];
    }
    int ans=0;
    if (s[ind1] == t[ind2]) {
        ans = 1 + f(s, t, ind1 - 1, ind2 - 1, memo);
    } else {
        ans = max(f(s, t, ind1 - 1, ind2, memo), f(s, t, ind1, ind2 - 1, memo));
    }
    return memo[ind1][ind2] = ans;
}
};