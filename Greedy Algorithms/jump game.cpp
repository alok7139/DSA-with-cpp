/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/
   bool canJump(vector<int>& nums) {
        int n=nums.size();
        int finalposition=n-1;
        // for(int i=n-2;i>=0;i--){
        //     if(i+nums[i]>=finalposition){
        //         finalposition=i;
        //     }
        // }
        // return finalposition==0;
        int farthest=0;
        int curr=0;
        for(int i=0;i<n;i++){
            farthest = max(farthest,i+nums[i]);
              if(i==curr){
                  curr=farthest;

               if(farthest>=finalposition){
                    return true;
                }
              }
                
            
        }
        return false;
        
    }