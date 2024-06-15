/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
*/
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<pair<int,int>>s;
        stack<pair<int,int>>st;
       vector<int>left(n);
       vector<int>right(n);
       long long count=0;
       for(int i=0;i<n;i++){
           count=1;
           while(!s.empty() and s.top().first>=arr[i]){
               count += s.top().second;
               s.pop();
           }
           s.push({arr[i],count});
           left[i]=count;
       }
       for(int i=n-1;i>=0;i--){
           count=1;
           while(!st.empty() and st.top().first>arr[i]){
               count += st.top().second;
               st.pop();
           }
           st.push({arr[i],count});
           right[i]=count;
       }
       int mod=1e9+7;
       long long count1=0;
       for(int i=0;i<n;i++){
           count1  = (count1 + ((long long)arr[i] * left[i] * right[i]) % mod) % mod;;
       }
       return (long long)count1%mod;



        
    }