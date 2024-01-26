/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
*/
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        unordered_map<char,char>map1;
        unordered_map<char,char>map2;
        for(int i=0;i<n;i++){
            char ch1=s[i];
            char ch2=t[i];
            if(map1.find(ch1)!=map1.end() and map1[ch1]!=ch2){
                return false;
            }
            if(map2.find(ch2)!=map2.end() and map2[ch2]!=ch1){
                return false;
            }
            map1[ch1]=ch2;
            map2[ch2]=ch1;
        }
        return true;
    }