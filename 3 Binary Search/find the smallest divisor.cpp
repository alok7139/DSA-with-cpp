/*
You are given an array of integers 'arr' and an integer 'limit'.



Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given integer's limit.
Sample Input 1 :
5
1 2 3 4 5
8  
Sample Output 1 :
3
Explanation for Sample Input 1 :
We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor, and the sum is 7(1 + 1 + 1 + 2 + 2) if we choose 3 as a divisor, which is less than the 'limit'.
Hence we return 3.

*/
int sum(vector<int>arr, int div, int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum += ceil((double)(arr[i])/(double)(div));
	}
	return sum;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
	int n=arr.size();
	
	/*int mini=INT_MAX,maxi=INT_MIN;
	for(int i=0;i<n;i++){
		//mini=min(mini,arr[i]);
		maxi=max(maxi,arr[i]);
	}
	for(int i=1;i<=maxi;i++){
        int sum=0;
		for(int j=0;j<n;j++){
			sum += ceil((double)(arr[j])/(double)(i));
		}
		if(sum<=limit){
			return i;
		}
	}
	return -1;*/
	int maxi=*max_element(arr.begin(),arr.end());
	int low=1,high=maxi;
	if(n>limit){
		return -1;
	}
	while(low<=high){
		int mid=(low+high)/2;
		if(sum(arr,mid,n)<=limit){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return low;
}