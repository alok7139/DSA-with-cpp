/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
*/

int strStr(string haystack, string needle) {
        int count=0;
        if(needle.size()>haystack.size()){
            return -1;
        }
        //first method
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(haystack[i]==needle[0]){
                if(haystack.substr(i,needle.size())==needle){
                    // count =i;
                    return i;
                }
            }
        }
        // int ind=haystack.find(needle);
        // if(ind!= string::npos) return ind;
        return -1;

        
    }