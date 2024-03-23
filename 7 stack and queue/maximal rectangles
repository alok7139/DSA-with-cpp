/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
*/
    int maximalRectangle(vector<vector<char>>& matrix) {
        // dp solution
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>left(m,0),right(m,m),height(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int currleft=0,currright=m;
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') left[j] = max(left[j],currleft);
                else {left[j]=0; currleft=j+1;}
            }
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1') right[j] = min(currright,right[j]);
                else{
                    right[j]=m;
                    currright=j;
                }
            }
            for(int j=0;j<m;j++){
                ans = max(ans, (right[j]-left[j])*height[j]);
            }
        }
        return ans;


      //stack solution
        // int n=matrix.size();
        // int m=matrix[0].size();
        // int maxi=0;
        // vector<int>height(m,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]=='1')height[j]++;
        //         else height[j]=0;
        //     }
        //     int area=largestRectangle(height);
        //     maxi=max(maxi,area);
        // }
        // return maxi;
        // return largestRectangle(height);
        
    }
    int largestRectangle(vector<int> &arr) {
  // Write your code here
   int n=arr.size();
   stack<int>st;
   int leftsmaller[n],rightsmaller[n];
   for(int i=0;i<n;i++){
     while(!st.empty() and arr[st.top()]>=arr[i]){
       st.pop();
     }
     if(st.empty())leftsmaller[i]=0;
     else leftsmaller[i]=st.top()+1;
     st.push(i);
   }
   while(!st.empty()){
     st.pop();
   }
   for(int i=n-1;i>=0;i--){
     while(!st.empty() and arr[st.top()]>arr[i]){
       st.pop();
     }
     if(st.empty())rightsmaller[i]=n-1;
     else rightsmaller[i]=st.top()-1;
     st.push(i);
   }
   int maxi=0;
   for(int i=0;i<n;i++){
     maxi=max(maxi,(rightsmaller[i]-leftsmaller[i]+1)*arr[i]);
   }
   return maxi;


}