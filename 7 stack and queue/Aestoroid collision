/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
*/
    vector<int> asteroidCollision(vector<int>& arr) {
       int n=arr.size();
       vector<int>ans;
       stack<int>st;
       for(int i=0;i<n;i++){
           if(arr[i]>0 or st.empty()){
               st.push(arr[i]);
           }
           else{
               while(!st.empty() and st.top()>0 and abs(arr[i])>st.top()){
                   st.pop();
               }
               if(!st.empty() and st.top()==abs(arr[i])){
                   st.pop();
               }
               else if(st.empty() or st.top()<=0){
                   st.push(arr[i]);
               }
           }
       }
       while(st.size()>0){
           ans.push_back(st.top());
           st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
        
    }