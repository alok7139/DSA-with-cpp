/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
*/
 string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        if(n==0){
            return ans;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(palindrome(s,i,j)){
                    if(maxi<j-i+1){
                        maxi=j-i+1;
                        ans=s.substr(i,maxi);
                    }
                }
            }
        }
        return ans;
    }
    bool palindrome(string &s,int st,int e){
        
        while(st<e){
            if(s[st]!=s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }