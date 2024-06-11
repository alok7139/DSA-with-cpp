/*
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
*/
//code
 void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int n=r-l+1;
         long long temp[n];
         int left=l;
         int right=m+1;
         int i=0;
         while(left<=m and right<=r){
             if(arr[left]<=arr[right]){
                 temp[i]=arr[left];
                 left++;
             }
             else{
                 temp[i]=arr[right];
                 right++;
             }
             i++;
         }
         while(left<=m){
             temp[i]=arr[left];
                 left++;
                 i++;
         }
         while(right<=r){
             temp[i]=arr[right];
                 right++;
                 i++;
         }
         for(int i=l;i<=r;i++){
             arr[i]=temp[i-l];
         }
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l==r){
            return ;
        }
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }