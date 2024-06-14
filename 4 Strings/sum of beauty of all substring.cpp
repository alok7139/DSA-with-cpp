/*The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
*/
   int beautySum(string s) {
        int n=s.size();
	    int ans=0;
        for(int i=0;i<n;i++){
            map<char,int>p;
            for(int j=i;j<n;j++){
                p[s[j]]++;
                int mini=1e9;
                int maxi=-1e9;
                for(auto it:p){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                ans += (maxi-mini);
            }
        }
        return ans;
    }