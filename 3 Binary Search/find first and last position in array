/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

*/
 int findfirst(vector<int>&arr, int n, int k){
       int low=0, high=n-1;
       int first=-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(arr[mid]==k){
               first=mid;
               high=mid-1;
           }
           else if(arr[mid]>k){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
       }
       return first;
   }
   int findlast(vector<int>&arr, int n, int k){
       int low=0, high=n-1;
       int last=-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(arr[mid]==k){
               last=mid;
               low=mid+1;
           }
           else if(arr[mid]>k){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
       }
       return last;
   }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=findfirst(nums,n,target);
        int last=findlast(nums,n,target);
        return {first,last};
    }