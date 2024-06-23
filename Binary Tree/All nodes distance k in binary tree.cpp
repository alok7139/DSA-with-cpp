/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
*/
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*,TreeNode*>parentvisit;
    parent(root,parentvisit);
    unordered_map<TreeNode*,bool>visited;
    queue<TreeNode*>q;
    q.push(target);
    visited[target]=true;
    int distance=0;
    while(!q.empty()){
        int size=q.size();
        if(distance == k){
            break;
        }
        for(int i=0;i<size;i++){
           TreeNode* temp=q.front();
            q.pop();
            if(temp->left and !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right and !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(parentvisit[temp] and !visited[parentvisit[temp]]){
                q.push(parentvisit[temp]);
                visited[parentvisit[temp]]=true;
            }
        }
        distance++;
    }
    vector<int>ans;
    while(!q.empty()){
        TreeNode*temp=q.front();
        ans.push_back(temp->val);
        q.pop();
    }
    return ans;
    
}
void parent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parentvisit){
    if(root==nullptr){
        return ;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*temp=q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
            parentvisit[temp->left]=temp;
        }
        if(temp->right){
            q.push(temp->right);
            parentvisit[temp->right]=temp;
        }
    }
}