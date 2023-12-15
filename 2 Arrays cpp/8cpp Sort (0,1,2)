/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
//code
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int zero=0,one=0,two=n-1;
    while(one<=two){
        if(arr[one]==0){
            swap(arr[zero],arr[one]);
            one++;
            zero++;
        }
        else if(arr[one]==1){
            one++;
        }
        else{
            swap(arr[one],arr[two]);
            two--;
        }
    }
}