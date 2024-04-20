/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
*/
bool isSameTree(TreeNode* root1, TreeNode* root2) {
    //      if(root1==nullptr){
    //     if(root2==nullptr){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }	
    if(root1==nullptr and root2==nullptr){
        return true;
    } 
    if(root1==nullptr or root2==nullptr){
        return false;
    } 
    // if(root1->data!=root2->data){
    //     return false;
    // }
    queue<TreeNode*>st1,st2;
    st1.push(root1);
    st2.push(root2);
    while(!st1.empty() and !st2.empty()){
        TreeNode*temp1=st1.front();
        TreeNode*temp2=st2.front();
        st1.pop();
        st2.pop();
        if(temp1->val!=temp2->val){
            return false;
        }
        if(temp1->left!=nullptr and temp2->left==nullptr){
            return false;
        }
        if(temp1->left==nullptr and temp2->left!=nullptr){
            return false;
        }

        if(temp1->right!=nullptr and temp2->right==nullptr){
            return false;
        }
        if(temp1->right==nullptr and temp2->right!=nullptr){
            return false;
        }

        if(temp1->left!=nullptr and temp2->left!=nullptr){
            st1.push(temp1->left);
            st2.push(temp2->left);
        }
        if(temp1->right!=nullptr and temp2->right!=nullptr){
            st1.push(temp1->right);
            st2.push(temp2->right);
        }


    }
    return true;
        
    }