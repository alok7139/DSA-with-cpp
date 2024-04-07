/*
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

Sample Input 1:
1
2
3 
3 5 9 
4 
1 2 3 8   
Sample Output 1:
1 2 3 3 5 8 9 
Explanation of Sample Input 1:
After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], the output sorted array will be [1, 2, 3, 3, 5, 8, 9].
*/
#include <bits/stdc++.h> 
class node{
    public:
    int data,i,j;
    node(int data,int row,int col){
        this->data=data;
        i=row;
        j=col;
    }
};
class compare{
    public:
    bool operator()(node *a,node*b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
   priority_queue<node*,vector<node*>,compare>pq;
    vector<int>ans;
    for(int i=0;i<k;i++){
        node *temp=new node(kArrays[i][0],i,0);
        pq.push(temp);
    }
    while(!pq.empty()){
        node *temp=pq.top();
        ans.push_back(temp->data);
        pq.pop();

        int i = temp->i;
        int j = temp->j;
        if(j+1<kArrays[i].size()){
            node *next=new node(kArrays[i][j+1],i,j+1);
            pq.push(next);
        }
    }
    
    return ans;
}