/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
*/


class Solution {
public:
    bool isMatch(string s, string p) {
      int n = p.size();
    int m = s.size();
    vector<vector<int>>dp(n,vector<int>(m+1,-1));
    return f(p, s, n - 1, m - 1,dp);
        
    }
bool isallstars(string &s, int ind) {
    for (int i = 0; i <= ind; i++) {
        if (s[i] != '*') {
            return false;
        }
    }
    return true;
}

bool f(string &s, string &t, int ind1, int ind2,vector<vector<int>>&dp) {
    if (ind1 < 0 && ind2 < 0) {
        return true;
    }
    if (ind1 < 0 && ind2 >= 0) {
        return false;
    }
    if (ind1 >= 0 && ind2 < 0) {
        return isallstars(s, ind1);
    }
    if(dp[ind1][ind2]!=-1){
       return dp[ind1][ind2];
    }

    if (s[ind1] == t[ind2] || s[ind1] == '?') {
        return dp[ind1][ind2]=  f(s, t, ind1 - 1, ind2 - 1,dp);
    } else {
        if (s[ind1] == '*') {
            return dp[ind1][ind2]=  f(s, t, ind1 - 1, ind2,dp) || f(s, t, ind1, ind2 - 1,dp);
        } else {
            return false;
        }
    }
}
};