/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

class Solution {
public:
  int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        // return lcs(s1,s2);
        return f(s1,s2,n-1,m-1,dp);
    }
    int f(string s1, string s2,int i,int j,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
           ans = f(s1,s2,i-1,j-1,dp);
        }
        else{
            ans = 1+min(f(s1,s2,i-1,j-1,dp),min(f(s1,s2,i-1,j,dp),f(s1,s2,i,j-1,dp)));
        }
        return dp[i][j]=ans;
    }
    int lcs(string &s,string &t){
        int n=s.size();
        int m=t.size(); 
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++){
		dp[i][0]=i;
	}
	for(int i=0;i<=m;i++){
		dp[0][i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]= dp[i-1][j-1];
			}
			else{
                // i-1,j-1 is replace and i-1,j is delete and i,j-1 is insert
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}
		}
	}
	return dp[n][m];
}
};