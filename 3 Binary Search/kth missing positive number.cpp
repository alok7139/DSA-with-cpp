/*
You are given a strictly increasing array 'vec' and a positive integer 'k'.



Find the 'kth' positive integer missing from 'vec'.



Example :
Input: vec = [2,4,5,7] , k = 3

Output: 6

Explanation : 
In the given example, first missing positive integer is 1 second missing positive integer is 3, and the third missing positive integer is 6.
Hence the answer is 6.
*/
int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
   /* for(int i=0;i<n;i++){
        if(vec[i]<=k){
            k++;
        }
        else
        break;
    }
    return k;*/
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=vec[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high+k+1;
}