/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
*/
class Solution {
    int depth(TreeNode* root){
        if(root==nullptr){
            return 0;
        } 
        return 1+max(depth(root->left),depth(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // return height_diameter(root).second;
        if(root==nullptr){
            return 0;
        }
        int height = depth(root->left)+depth(root->right);
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        return max(height,max(option1,option2));
    }
    pair<int,int>height_diameter(TreeNode *root){
    if(root==nullptr){
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>leftans=height_diameter(root->left);
    pair<int,int>rightans=height_diameter(root->right);
    int leftheight=leftans.first;
    int leftdiameter=leftans.second;
    int rightheight=rightans.first;
    int rightdiameter=rightans.second;
    int height = 1+max(leftheight,rightheight);
    int diameter=max(leftheight+rightheight,max(leftdiameter,rightdiameter));
    pair<int,int>ans;
    ans.first=height;
    ans.second=diameter;
    return ans;

     
}
};