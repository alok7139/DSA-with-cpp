/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
*/
  bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        unordered_map<char,int>p;
        for(int i=0;i<n;i++){
            p[s[i]]++;
            p[t[i]]--;
        }
        for(auto ele:p){
            if(ele.second!=0){
                return false;
            }
        }
        return true;
    }