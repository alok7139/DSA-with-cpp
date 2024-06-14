/*
A subsequence of a string is achieved by removing some (possibly 0) characters without changing the order of the remaining characters.



You have been given a string 's'.



Find the number of non-empty palindromic subsequences (not necessarily be distinct) in string 's' and return that number modulo 10 ^ 9 + 7.



Example :
Input: 's' = "pqqr"

Output: 5

Explanation: The subsequences are:

p

q

q

r

qq

Please note that both "q" are considered different.
*/

int rec(string&str,vector<vector<int>>&dp,int i,int j)

{

    int mod =1e9+7;

    if(i==j) return 1;

    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    if(str[i]==str[j])

    {

        dp[i][j]=(1+rec(str,dp,i+1,j)+rec(str,dp,i,j-1))%mod;

    }

    else

    {

        dp[i][j]=((rec(str,dp,i+1,j)+rec(str,dp,i,j-1)-rec(str,dp,i+1,j-1))%mod+mod)%mod;

    }

    return dp[i][j];

}
int countPalindromicSubsequences(string &s){
	// Write your code here.
	int n=s.size();
	
	vector<vector<int>>dp(n,vector<int>(n,-1));
	return rec(s,dp,0,n-1);
}