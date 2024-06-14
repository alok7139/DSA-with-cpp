/*
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
*/


    string shortestPalindrome(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        string curr = s+"#"+t;
        vector<int>lps(curr.size(),0);
        solve(lps,curr);
        int i=lps[curr.size()-1];
        string temp = s.substr(i);
        reverse(temp.begin(),temp.end());
        return temp+s;
        
    }
    void solve(vector<int>&lps,string s){
        int n=s.size();
        int i=0,j=1;
        while(j<n){
            if(s[i]==s[j]){
                i++;
                lps[j]=i;
                j++;
            }
            else{
                if(i==0){
                    j++;
                }
                else{
                    i=lps[i-1];
                }
            }
        }
    }