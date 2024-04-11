/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
*/
    int candy(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                ans[i]=1+ans[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                ans[i]=max(ans[i],1+ans[i+1]);
            }
        }
        int sum=0;
        for(auto ele:ans){
            sum += ele;
        }
        return sum;
        
    }