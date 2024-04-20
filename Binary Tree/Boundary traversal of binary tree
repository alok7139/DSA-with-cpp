/*
You are given a binary tree having 'n' nodes.



The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, each node considered once.



Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.



Example :
Input: Consider the binary tree A as shown in the figure:

Output: [10, 5, 3, 7, 18, 25, 20]

Explanation: As shown in the figure

The nodes on the left boundary are [10, 5, 3]

The nodes on the right boundary are [10, 20, 25]

The leaf nodes are [3, 7, 18, 25].

Please note that nodes 3 and 25 appear in two places but are considered once
*/
#include <bits/stdc++.h>

bool isleaf(TreeNode<int>*root){
    if(root->left==nullptr and root->right==nullptr){
        return true;
    }
    
        return false;
    
}
void leftnode(TreeNode<int> *root,vector<int>&v){
    // if(root==nullptr){
    //     return;
    // }
    while(root){
        if(!isleaf(root)) v.push_back(root->data);
        if(root->left) root=root->left;
        else root=root->right;
    }
}
void rightnode(TreeNode<int> *root,vector<int>&v){
    // if(root==nullptr){
    //     return;
    // }
    stack<int>q;
    while(root){
        if(!isleaf(root)) q.push(root->data);
        if(root->right) root=root->right;
        else root=root->left;
    }
    while(!q.empty()){
        v.push_back(q.top());
        q.pop();
    }
    
}
void leafnode(TreeNode<int> *root,vector<int>&v){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr and root->right==nullptr){
        v.push_back(root->data);
        // return;
    }
    leafnode(root->left, v);
    leafnode(root->right,v);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int>ans;
    if(root==nullptr){
        return ans;
    }
    
    // vector<int>v1,v2,v3;
    if (!isleaf(root)) {
        ans.push_back(root->data);
    }
        leftnode(root->left, ans);
        leafnode(root, ans);
        rightnode(root->right, ans);
 
    return ans;
}