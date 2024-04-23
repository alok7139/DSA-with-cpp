/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
*/

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
        return true;
    }
    return isSymmetric(root->left,root->right);
    }
    bool isSymmetric(TreeNode *root1,TreeNode *root2){
    if(root1==nullptr and root2==nullptr){
        return true;
    }
    // if(root1==nullptr or root2==nullptr) return false;
    if(root1==nullptr and root2!=nullptr){
        return false;
    }
    if(root1!=nullptr and root2==nullptr){
        return false;
    }

    return (root1->val==root2->val) and isSymmetric(root1->left, root2->right) and isSymmetric(root1->right,root2->left);
}