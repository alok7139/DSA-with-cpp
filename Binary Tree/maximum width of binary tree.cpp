/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
*/
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
    if(!root){
        return 0;
    }
    queue<pair<TreeNode*,long long>>q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int first,last;
        for(int i=0;i<size;i++){
            int curr = q.front().second;
            TreeNode* temp=q.front().first;
            q.pop();
            if(i==0){
                first=curr;
            }
            if(i==size-1){
                last=curr;
            }
            if(temp->left){
                q.push({temp->left,(long long)curr*2+1});
            }
            if(temp->right){
                q.push({temp->right,(long long)curr*2+2});
            }
        }
        ans=max(ans,last-first+1);
    }
    
    return ans;
        
    }