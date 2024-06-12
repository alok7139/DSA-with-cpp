/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

*/
int findmaxvalue(vector<vector<int>>v, int n, int m, int col){
    int maxvalue=-1,index=-1;
    for(int i=0;i<n;i++){
        if(v[i][col]>maxvalue){
            maxvalue=v[i][col];
            index=i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here. 
    int n=g.size();
    int m=g[0].size();
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int findpeakindex=findmaxvalue(g,n,m,mid);
        int left=mid-1>=0?g[findpeakindex][mid-1]:-1;
        int right=mid+1<m?g[findpeakindex][mid+1]:-1;
        if(left<g[findpeakindex][mid] and right<g[findpeakindex][mid]){
            return {findpeakindex,mid};
        }
        else if(g[findpeakindex][mid]<left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
}