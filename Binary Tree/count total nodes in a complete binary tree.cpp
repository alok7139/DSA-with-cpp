/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
*/
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
    return 0;
  }
  // base solution

  int ans = 0;
// vector<int>ans;
  queue<TreeNode *> q;
  q.push(root);
  while(!q.empty()){
      int size=q.size();
      ans += size;
      for(int i=0;i<size;i++){
      TreeNode *temp=q.front();
      q.pop();
      if(temp->left){
          q.push(temp->left);
      }
      if (temp->right) {
          q.push(temp->right);
      }
      }
  }
  return ans;
        
    }