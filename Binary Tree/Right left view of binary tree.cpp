/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
*/

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
    if(root==nullptr){
        return ans;
    }
    
    rightview(root,0,ans);
    return ans;
    }
    void rightview(TreeNode* root,int level,vector<int>&ans){
    if(root==nullptr){
        return;
    }
    if(level==ans.size()) ans.push_back(root->val);
    rightview(root->right, level+1, ans);
    rightview(root->left, level+1, ans);

    
}