/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

*/
bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
   // bool ans=false;
    int n= A.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]==key){
            return true;
        }
        if(A[low]<=A[mid]){
          if(A[low]<=key and key<=A[mid]){
            high=mid-1;
          }
          else{
              low=mid+1;
          }
        }
        else{
            if(A[high]>=key and key>=A[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
}