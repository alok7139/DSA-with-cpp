/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxpath(root,maxi);
        return maxi;
        
    }
    int maxpath(TreeNode *root,int &maxi){
    if(root==nullptr){
        return 0;
    }
    int leftsum=max(0,maxpath(root->left,maxi));
    int rightsum=max(0,maxpath(root->right,maxi));
    //int val=root->data;
     maxi=max(maxi,(leftsum+rightsum)+root->val);
     return root->val + max(leftsum,rightsum);

}