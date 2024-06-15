/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        string ans="";
        if(k>=n){
            return "0";
        }
        if(k==0){
            return num;
        }
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top()>num[i] and k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size()==1 and num[i]=='0'){
                st.pop();
            }
            
        }
        while(k and !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            return "0";
        }
        
        return ans;
    }