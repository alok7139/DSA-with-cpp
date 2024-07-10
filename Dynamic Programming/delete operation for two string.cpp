/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
*/

class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
    int m=s2.size();
    int k=lcs(s1,s2,n,m);
    return (n-k)+(m-k);
    }
    int lcs(string s,string t,int n,int m){
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
};