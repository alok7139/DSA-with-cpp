/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
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
//   private:
  Node* root;
  public:
  trie(){
      root=new Node();
  }
  
  void insert(int num){
      Node*node=root;
      for(int i=31;i>=0;i--){
          int bit=(num>>i)&1;
          if(node->child[bit]==nullptr){
              node->child[bit]= new Node();
          }
          node=node->child[bit];
      }
  }

  int getmax(int num){
      Node*node=root;
      int maxi=0;
      for(int i=31;i>=0;i--){
          int bit=(num>>i)&1;
          if(node->child[1-bit]!=nullptr){
              node=node->child[1-bit];
              maxi= maxi|(1<<i);
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
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        // base solution
        // long long maxi=0;
        // long  i=0;
        // while(i<n){
        //     int first=nums[i];
        //     for(long j=i+1;j<n;j++){
        //         long long xorsum=first^nums[j];
        //         maxi=max(maxi,xorsum);
        //     }
        //     i++;
        // }
        // return maxi;
        trie t;
        for(auto i:nums){
            t.insert(i);
        }
        int maxi=0;
        for(auto i:nums){
            maxi=max(maxi,t.getmax(i));
        }
        return maxi;
        
    }
};