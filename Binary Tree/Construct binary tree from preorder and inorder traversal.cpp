/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=inorder.size();
return solve(inorder,preorder,0,n-1,0,n-1);
}
TreeNode* solve(vector<int> &inorder, vector<int> &preorder,int ins,int ine,int pres, int pree){
if(ins>ine){
  return nullptr;
}
int rootdata=preorder[pres];
int rootindex=-1;
for(int i=ins;i<=ine;i++){
  if(inorder[i]==rootdata){
      rootindex=i;
      break;
  }
}
int lins=ins;
int line=rootindex-1;
int lpres=pres+1;
int lpree=line-lins+lpres;
int rins=rootindex+1;
int rine=ine;
int rpres=lpree+1;
int rpree=pree;

TreeNode* root=new TreeNode(rootdata);
root->left=solve(inorder,preorder,lins,line,lpres,lpree);
root->right=solve(inorder,preorder,rins,rine,rpres,rpree);
return root;

}