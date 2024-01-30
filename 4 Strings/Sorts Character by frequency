/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/
string frequencySort(string s) {
        int n=s.size();
      unordered_map<char,int>p;
      for(int i=0;i<n;i++){
          p[s[i]]++;
      }
      vector<pair<int,char>>q;
      for(auto it:p){
          q.push_back({it.second,it.first});
      }
       sort(q.rbegin(),q.rend());
      string ans="";
      for(auto it:q){
          ans += string(it.first,it.second);
      }
      return ans;
    }