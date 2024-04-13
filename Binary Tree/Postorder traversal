/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
*/
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
        
    }
    void postorder(TreeNode*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);

}