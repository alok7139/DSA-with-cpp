/*
Given an integer numRows, return the first numRows of Pascal's triangle.
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/
vector<int>generaterow(int row){
    long long ans=1;
    vector<int>v;
    v.push_back(ans);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans/=col;
        v.push_back(ans);
    }
    return v;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }