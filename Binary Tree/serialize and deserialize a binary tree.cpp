/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
*/
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "";
        }
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp==nullptr){
                s += "#,";
            }
            else{
                s += to_string(temp->val)+',';
            }
            if(temp!=nullptr){
                q.push(temp->left);
                q.push(temp->right);

            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data) {
        if(data.size()==0){
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root= new TreeNode (stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*temp;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                temp->left=nullptr;
            }
            else{
                TreeNode* left=new TreeNode(stoi(str));
                temp->left=left;
                q.push(left);
            }
            getline(s,str,',');
            if(str=="#"){
                temp->right=nullptr;
            }
            else{
                TreeNode* right =new TreeNode(stoi(str));
                temp->right=right;
                q.push(right);
            }
        }
    return root;
        
    }