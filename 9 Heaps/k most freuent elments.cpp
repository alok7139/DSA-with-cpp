/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==k){
            return nums;
        }
        map<int,int>p;
        priority_queue<pair<int,int>>pq;
        for(auto i:nums){
            p[i]++;
        }
        vector<int>ans;
        for(auto it:p){
            pq.push({it.second,it.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

        
    }