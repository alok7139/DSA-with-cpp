/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    set<vector<int>>st;
    int n=nums.size();
    vector<vector<int>>v;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 and nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 and nums[j]==nums[j-1])continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    v.push_back(temp);
                    k++;
                    l--;
                    while(k<l and nums[k]==nums[k-1])k++;
                    while(k<l and nums[l]==nums[l+1])l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
    return v;
}