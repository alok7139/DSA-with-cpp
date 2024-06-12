/*
Problem statement
You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.



Find the total number of occurrences of 'x' in the array/list.



Example:
Input: 'n' = 7, 'x' = 3
'arr' = [1, 1, 1, 2, 2, 3, 3]

Output: 2

Explanation: Total occurrences of '3' in the array 'arr' is 2.

*/
int findfirst(vector<int>&arr, int n, int x){
	int low=0,high=n-1;
	int first=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==x){
			first=mid;
			high=mid-1;
		}
		else if(arr[mid]>x){
            high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return first;
}
int findlast(vector<int>&arr, int n, int x){
	int low=0,high=n-1;
	int last=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==x){
			last=mid;
			low=mid+1;
		}
		else if(arr[mid]>x){
            high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return last;
}
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	//int low=0,high=n-1;
	/*int count=0;
	while(low<=high){
		long long mid=low+(high-low)/2;
		if(arr[mid]==x){
          count +=1;
		  int left=mid-1;
		  while(left>=0 and arr[left]==x){
			  count+=1;
			  left--;
		  }
		  int right=mid+1;
		  while(right<n and arr[right]==x){
			  count+=1;
			  right++;
		  }
		  return count;
		}
		else if(arr[mid]<x){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return count;*/
	//first occurence
	int first=findfirst(arr,n,x);
	int last=findlast(arr,n,x);
	if(first==-1){
		return 0;
	}
	return (last-first+1);
}
