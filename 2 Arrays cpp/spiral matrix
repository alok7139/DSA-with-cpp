/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=0;
        int row=n-1,column=m-1;
        while(low<=row and high<=column){
            for(int i=low;i<=column;i++){
                v.push_back(matrix[high][i]);
            }
            high++;
            for(int i=high;i<=row;i++){
                v.push_back(matrix[i][column]);
            }
            column--;
            if(high<=row){
                for(int i=column;i>=low;i--){
                    v.push_back(matrix[row][i]);
                }
                row--;
            }
            if(low<=column){
                for(int i=row;i>=high;i--){
                    v.push_back(matrix[i][low]);
                }
                low++;
            }
        }
        return v;
    }