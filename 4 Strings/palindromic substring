/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
*/
   int countSubstrings(string s) {
        int ans=0;
        if(s.size()==0){
            return 0;
        }

        // there time complexity would be O(n^3) where N^2 for two lopp and another n for checking the string is palindrome or not
        // brute force
        // for(int i=0;i<s.size();i++){
        //     for(int j=i;j<s.size();j++){
        //         if(palindrome(s,i,j)){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
       

       // t.C O(N^2) one for this loop and other for countplaindrome linear search the string
       //optimize
        for(int i=0;i<s.size();i++){
            int even = countpalindrome(s,i,i+1);
            int odd = countpalindrome(s,i,i);
            ans += even+odd;
        }
        return ans;

        
    }
    int countpalindrome(string &s,int left,int right){
        int count=0;
        while(left>=0 and right<s.size() and s[left]==s[right]){
                left--;
                right++;
                count++;

        }
        return count;
    }

    bool palindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }