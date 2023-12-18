/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:

Input: nums = [3,2,3]
Output: 3
*/
int majorityElement(vector<int>& nums) {
        unordered_map<int,int>p;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            p[nums[i]]++;
        }
       
        for(auto ele:p){
            if(ele.second>n/2){
                return ele.first;
                
            }
        }
        return 0;
    }