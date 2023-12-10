
/*
statement
 Given an unsorted array of size N, use selection sort to sort arr[] in increasing order.
 Input:
N = 5
arr[] = {4, 1, 3, 9, 7}
Output:
1 3 4 7 9
 */
// #code
void selectionSort(vector<int>&arr) {
    // Write your code here.
    int n=arr.size();
     for (int i=0;i<=n-2;i++){
      int x=i;
      for(int j=i;j<n;j++){
          if(arr[j]<arr[x]){
              x=j;
          }
      }
      swap(arr[x],arr[i]);
    }
}
