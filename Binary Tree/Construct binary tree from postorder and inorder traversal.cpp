/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n=postorder.size();
return solve(postorder,inorder,0,n-1,0,n-1);
}
TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int ps,int pe,int ins,int ine){
if(ins>ine){
     return nullptr;
}
int rootdata=postorder[pe];
int rootindex=-1;
for(int i=ins;i<=ine;i++){
     if(inorder[i]==rootdata){
          rootindex=i;
          break;
     }
}
int lins=ins;
int line=rootindex-1;
int lposts=ps;
int lposte=line-lins+ps;
int rins=rootindex+1;
int rine=ine;
int rposts=lposte+1;
int rposte=pe-1;
TreeNode* root=new TreeNode(rootdata);
root->left=solve(postorder,inorder,lposts,lposte,lins,line);
root->right=solve(postorder,inorder,rposts,rposte,rins,rine);
return root;


}