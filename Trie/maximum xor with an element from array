/*
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
*/

class Node{
    public:
   Node* child[2];
   
   Node(){
     this->child[0]=nullptr;
     this->child[1]=nullptr;
   }
};
class trie{
    public:
   Node* root;
   trie(){
    root=new Node();
   } 
   void insert(int num){
      Node* node= root;
    for(int i=31;i>=0;i--){
        int bit = (num>>i)&1;
        if(node->child[bit]==nullptr){
            node->child[bit] = new Node();

        }
        node=node->child[bit];
    }
   }
   int getmax(int num){
    Node*node=root;
    long maxi=0;
    for(int i=31;i>=0;i--){
        int bit = (num>>i)&1;
        if(node->child[1-bit]){
            node=node->child[1-bit];
            maxi = maxi|(1<<i);
        }
        else{
            node=node->child[bit];
        }
    }
    return maxi;
   }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        // brute solution
//         int n=nums.size();
//         int m=queries.size();
//         vector<int>ans(m,-1);
//         for(int i= 0; i < m; i++){
// 	  for(int j=0;j<n;j++){
// 		  if(nums[j]<=queries[i][1]){
// 			  ans[i]=max(ans[i],nums[j]^queries[i][0]);
// 		  }
// 	  }
//   }
//   return ans;    
           int n=arr.size();
           int m = queries.size();
           vector<int>ans(m,0);
           vector<pair<long,pair<long,long>>>offline;
           int index=0;
           for(auto it:queries){
              offline.push_back({it[1],{it[0],index++}});
           }  
           sort(arr.begin(),arr.end());
           sort(offline.begin(),offline.end());
           long i=0;
           trie t;
           for(auto it:offline){
            while(i<n and arr[i]<=it.first){
                // i++;
                t.insert(arr[i]);
                i++;
            }
            if(i!=0) ans[it.second.second] = t.getmax(it.second.first);
            else ans[it.second.second]=-1;
           }
           return ans;
    }
};