/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
*/
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        stack<TreeNode*>st1,st2;
        st1.push(root);
        bool left_to_right=true;
        while(!st1.empty()){
          int size=st1.size();
            vector<int>v;
            for(int i=0;i<size;i++){
            TreeNode* temp=st1.top();
            st1.pop();
            if(temp){
                v.push_back(temp->val);
                if(left_to_right){
                    if(temp->left!=nullptr){
                        st2.push(temp->left);
                    }
                    if(temp->right!=nullptr){
                        st2.push(temp->right);
                    }
                }
                else{
                    if(temp->right!=nullptr){
                        st2.push(temp->right);
                    }
                    if(temp->left!=nullptr){
                        st2.push(temp->left);
                    }
                }
            }

            if(st1.size()==0){
                left_to_right=!left_to_right;
                swap(st1,st2);
            }
            }
            ans.push_back(v);
            }
        return ans;
        
    }