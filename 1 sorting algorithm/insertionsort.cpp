/*
The task is to complete the insert() function which is used to implement Insertion Sort.
Input:
N = 5
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9
*/
// code
void insertionSort(int arr[], int n)
    {
        //code here
        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 and arr[j-1]>arr[j]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                j--;
            }
        }
    }