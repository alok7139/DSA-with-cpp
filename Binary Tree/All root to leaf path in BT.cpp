/*
You are given an arbitrary binary tree consisting of 'N' nodes numbered from 1 to 'N'. Your task is to print all the root to leaf paths of the binary tree.

A leaf of a binary tree is the node which does not have a left child and a right child.



For Example :
Given a binary tree :

All the root to leaf paths are :
1 2 4
1 2 5 
1 3
Note :

1. Two nodes may have the same value associated with it.
2. The root node will be fixed and will be provided in the function.
3. Note that the nodes in a path will appear in a fixed order. For example, 1 2 3 is not the same as 2 1 3.
4. Each path should be returned as a string consisting of nodes in order and separated by a space.
5. The path length may be as small as ‘1’.
*/

 bool getPath(TreeNode* root, vector<int>& arr, int x) {
        // Base case: If the current
        // node is null, return false
        if (!root) {
            return false;
        }

        // Add the current node's
        // value to the path vector
        arr.push_back(root->val);

        // If the current node's value is equal
        // to the target value 'x', return true
        if (root->val == x) {
            return true;
        }

        // Recursively search for the target value
        // 'x' in the left and right subtrees
        if (getPath(root->left, arr, x)
            || getPath(root->right, arr, x)) {
            return true;
        }

        // If the target value 'x' is not found
        // in the current path, backtrack
        arr.pop_back();
        return false;
    }

    // Function to find and return the path from
    // the root to a given node with value 'B'
    vector<int> solve(TreeNode* A, int B) {
        // Initialize an empty
        // vector to store the path
        vector<int> arr;

        // If the root node is null,
        // return the empty path vector
        if (A == NULL) {
            return arr;
        }

        // Call the getPath function to find
        // the path to the node with value 'B'
        getPath(A, arr, B);

        // Return the path vector
        return arr;
    }