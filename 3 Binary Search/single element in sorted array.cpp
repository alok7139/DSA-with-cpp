/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n=arr.size();
	int low=0,high=n-1;
	//int ans=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]){
			return arr[mid];
		}
		if((mid%2==1 and arr[mid]==arr[mid-1]) or (mid%2==0 and arr[mid]==arr[mid+1])){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return -1;
}