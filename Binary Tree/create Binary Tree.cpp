/*
Given an array 'arr' that contains 7 integers representing the values of nodes in a binary tree. This represents level order. The first element of the array represents the value of the root node.



Your objective is to construct a binary tree using the remaining 6 elements of the array, creating nodes for each of these values and return root node.



For example:
arr = [11, 22, 3, 54, 15, 23, 21]
*/
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node *create(vector<int>&arr,int ind){
    if(ind>=arr.size()){
        return nullptr;
    }
    Node *root=new Node(arr[ind]);
    root->left=create(arr,2*ind+1);
    root->right=create(arr,2*ind+2);
    return root;
}

Node* createTree(vector<int>&arr){
    // Write your code here.
    
    return create(arr,0);
    

}