/*
You are given two strings ‘s1’ and ‘s2’.



Return the longest common subsequence of these strings.



If there’s no such string, return an empty string. If there are multiple possible answers, return any such string.



Note:
Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’. A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more (possibly zero) characters from ‘s1’.


Example:
Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

Output: “bab”

Explanation:
“bab” is one valid longest subsequence present in both strings ‘s1’ , ‘s2’.
*/

void f(int n,int m,string&s1,string&s2,vector<vector<int>>&dp){
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}	
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]= 1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
}

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	f(n,m,s1,s2,dp);
	int len=dp[n][m];
	int i=n;
	int j=m;
	int index=len-1;
	string str = "";
	for(int k=0;k<=index;k++){
        str +="$";
	}
	while(i>0 and j>0){
		if(s1[i-1]==s2[j-1]){
            str[index]=s1[i-1];
			index--;
			i--;
			j--;
		}
		else if(dp[i][j-1]<dp[i-1][j]){
            i--;
		}
		else{
            j--;
		}
	}
	return  str;

}