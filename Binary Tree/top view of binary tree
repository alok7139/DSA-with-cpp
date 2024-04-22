/*
You are given a Binary Tree of 'n' nodes.



The Top view of the binary tree is the set of nodes visible when we see the tree from the top.



Find the top view of the given binary tree, from left to right.



Example :
Input: Let the binary tree be:

Output: [10, 4, 2, 1, 3, 6]

Explanation: Consider the vertical lines in the figure. The top view contains the topmost node from each vertical line.
*/
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int>ans;
    if(root==nullptr){
        return ans;
    }
    map<int,int>p;
    queue<pair<TreeNode<int> *,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it =q.front();
        q.pop();
        TreeNode<int> *temp=it.first;
        int level=it.second;
        if(p.find(level)==p.end()) p[level]=temp->data;

        if(temp->left){
            q.push({temp->left,level-1});
        }
        if(temp->right){
            q.push({temp->right,level+1});
        }
    }
    for(auto it:p){
        ans.push_back(it.second);
    }
    return ans;
}
