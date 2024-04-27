/*
You have a binary tree of 'N' unique nodes and a Start node from where the tree will start to burn. Given that the Start node will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.



It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.



For Example :
For the given binary tree: [1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1]
Start Node: 3

    1
   / \
  2   3
     / \
    4   5

Output: 2

Explanation :
In the zeroth minute, Node 3 will start to burn.

After one minute, Nodes (1, 4, 5) that are adjacent to 3 will burn completely.

After two minutes, the only remaining Node 2 will be burnt and there will be no nodes remaining in the binary tree. 

So, the whole tree will burn in 2 minutes.
*/
#include <bits/stdc++.h>
BinaryTreeNode<int>* parent(BinaryTreeNode<int>* root,int start,unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&parentvisit){
    if(root==NULL){
        return nullptr;
    }
    BinaryTreeNode<int>*target;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>*temp=q.front();
        q.pop();
        if(temp->data==start){
            target=temp;
        }
        if(temp->left){
            q.push(temp->left);
            parentvisit[temp->left]=temp;
        }
        if(temp->right){
            q.push(temp->right);
            parentvisit[temp->right]=temp;
        }
    }
    return target;
}
int burntree(BinaryTreeNode<int>*target,unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&parentvisit){
    unordered_map<BinaryTreeNode<int>*,bool>visited;
    queue<BinaryTreeNode<int>*>q;
    q.push(target);
    visited[target]=true;
    int time=0;
    while(!q.empty()){
        bool visit=false;
        int n=q.size();
        for(int i=0;i<n;i++){
            BinaryTreeNode<int>*temp=q.front();
            q.pop();
             if(temp->left and !visited[temp->left]){
                 visit=true;
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right and !visited[temp->right]){
                visit=true;
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(parentvisit[temp] and !visited[parentvisit[temp]]){
                visit=true;
                q.push(parentvisit[temp]);
                visited[parentvisit[temp]]=true;
            }
        }
        if(visit){
            time++;
        }
    }
    return time;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>parentvisit;
   BinaryTreeNode<int>* target= parent(root,start,parentvisit);
    int ans=burntree(target,parentvisit);
    return ans;
}