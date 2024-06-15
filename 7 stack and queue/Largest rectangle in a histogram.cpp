/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/
    int largestRectangleArea(vector<int>& arr) {
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