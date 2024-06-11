/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

*/
vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
   vector<int>temp;
   for(int i=0;i<n;i++){
       if(a[i]!=0){
           temp.push_back(a[i]);
       }
   }
   int s=temp.size();
   for(int i=0;i<s;i++){
       a[i]=temp[i];
   }
   for(int i=s;i<n;i++){
       a[i]=0;
   }
   return a;
}