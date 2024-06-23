/*
Return true if all non-leaf nodes in a given binary tree have a value that is equal to the sum of their child nodes, otherwise return false..



For Example:

Output: true 
Explanation: Node 2 and 3 are children of Node 1 and (3+1)=4.

*/
bool isParentSum(Node *root){
    // Write your code here.
    if(root==nullptr){
        return true;
    }
    int ans=0;
    if(root->left){
        ans += root->left->data;
    }
    if(root->right){
        ans += root->right->data;
    }
    if(ans!=root->data && ans!=0){
        return false;
    }
    
    return isParentSum(root->left)&&isParentSum(root->right);
    

          
    

}