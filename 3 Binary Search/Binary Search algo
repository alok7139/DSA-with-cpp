/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4


*/
int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        return BS(nums,low,high,target);
        
    }
    int BS(vector<int>& nums,int low,int high, int target){
        if(low>high){
            return -1;
        }
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return BS(nums,low,mid-1,target);
        }
        else{
            return BS(nums,mid+1,high,target);
        }
    }