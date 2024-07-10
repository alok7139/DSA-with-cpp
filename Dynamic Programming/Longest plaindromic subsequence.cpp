/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string t=s;
    reverse(s.begin(),s.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    // return lcs(t,s);
    return lcs(t,s,n-1,n-1,dp);
        
    }
    int lcs(string &t,string&s,int i,int j,vector<vector<int>>&dp){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        if(t[i]==s[j]){
           ans = 1+ lcs(t,s,i-1,j-1,dp);
        }
        else{
            ans = max(lcs(t,s,i-1,j,dp) , lcs(t,s,i,j-1,dp));
        }
        return dp[i][j]=ans;
    }
    

    // int lcs(string &t,string &s){
    // int n=t.size();
    // int m=s.size();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(t[i-1]==s[j-1]){
    //             dp[i][j]=1+dp[i-1][j-1];
    //         }
    //         else{
    //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    // }
    // return dp[n][m];
// }
};