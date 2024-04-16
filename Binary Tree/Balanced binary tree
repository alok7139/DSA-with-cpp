/*
Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true

*/
bool isBalanced(TreeNode* root) {
    if(root==nullptr){
        return true;
    }
    int left=depth(root->left);
    int right=depth(root->right);
    int diff=abs(left-right);
    if(diff>1){
        return false;
    }
    if(!isBalanced(root->left)){
        return false;
    }
    if(!isBalanced(root->right)){
        return false;
    }
    return true;
    
}
int depth(TreeNode*root){
    if(root==nullptr){
        return 0;
    }
    int left=depth(root->left);
    int right=depth(root->right);
    int maxi=max(left,right);
    return maxi+1;
}