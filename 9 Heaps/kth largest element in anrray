/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/
 int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        // vector<int>ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        // return ans[k-1];
        int ans=0;
        // k=k-1;
        while(k){
          ans=pq.top();
          pq.pop();
          k--;
        }
        return ans;
    }