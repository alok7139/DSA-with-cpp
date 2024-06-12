/*
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.

Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).

*/

#include <bits/stdc++.h>
class trie{
    public:
    trie* children[26];

    trie(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
    bool containkey(char c){
        return children[c-'a']!=NULL;
    }
    trie *get(char c){
        return children[c-'a'];
    }
    void put(char c,trie*node){
        children[c-'a']=node;
    }

};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int count=0;
    trie*root=new trie();
    for(int i=0;i<s.size();i++){
        trie * node=root;
        for(int j=i;j<s.size();j++){
            if(!node->containkey(s[j])){
                count++;
                node->put(s[j],new trie());
            }
            node=node->get(s[j]);
        }
    }
    return count+1;
    
}