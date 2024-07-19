/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
*/

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n=a.size();
	int m=b.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int len= dp[n][m];
	int i=n;
	int j=m;

	string ans="";
	while(i>0 and j>0){
		if(a[i-1]==b[j-1]){
           ans += a[i-1];

		   i--;
		   j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){// up
			ans += a[i-1];
			i--;
		}
		else{  // diagonal
			ans += b[j-1];
			j--;
		}
	}
	while(i>0){
		ans += a[i-1];
		i--;
	}
	while(j>0){
		ans += b[j-1];
		j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;
        
    }
};