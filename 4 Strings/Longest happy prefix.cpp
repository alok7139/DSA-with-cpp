/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
*/

    string longestPrefix(string s) {
        int n=s.size();
        if(n==0){
            return "";
        }
        vector<int>prefix(n,0);
        int i=0,j=1;
        while(j<n){
            if(s[i]==s[j]){
                i++;
               prefix[j]=i;
               
               j++;
            }
            else{
                if(i==0){
                    j++;
                }
                else{
                    i=prefix[i-1];
                }
            }
        }
        return s.substr(0,prefix[n-1]);
        
    }