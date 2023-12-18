/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order
Sample Input 1:
5 5
4 1 2 3 1
Sample Output 1 :
YES
Explanation Of Sample Input 1:
Sam can buy 4 pages book and 1-page book.
*/
#include<bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    map<int,int>p;
    string ans="NO";
    for(int i=0;i<n;i++){
        if(p.find(target-book[i])!=p.end()){
            ans="YES";
        }
        p[book[i]]=i;
    }
    return ans;
}