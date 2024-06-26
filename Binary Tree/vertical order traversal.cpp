/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
*/
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>map;
    queue<pair<TreeNode*,pair<int,int>>>q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode*temp=it.first;
        int vertical=it.second.first;
        int level=it.second.second;
        map[vertical][level].insert(temp->val);
        if(temp->left){
          q.push({temp->left, {vertical - 1, level + 1}});
        }
        if(temp->right){
            q.push({temp->right, {vertical + 1, level + 1}});
        }
    }
    
    vector<vector<int>>ans;
    for(auto it:map){
        vector<int>v;
        for(auto ele:it.second){
            v.insert(v.end(),ele.second.begin(),ele.second.end());
        }
        ans.push_back(v);
    }
    
    return ans;
    }