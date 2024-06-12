/*
Given two sorted arrays 'a' and 'b' of size 'n' and 'm' respectively.



Find the median of the two sorted arrays.



Median is defined as the middle value of a sorted list of numbers. In case the length of list is even, median is the average of the two middle elements.



The expected time complexity is O(min(logn, logm)), where 'n' and 'm' are the sizes of arrays 'a' and 'b', respectively, and the expected space complexity is O(1).



Example:
Input: 'a' = [2, 4, 6] and 'b' = [1, 3, 5]

Output: 3.5

Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.
*/
double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	//vector<int>v;
	int n=a.size();
	int m=b.size();
	int i=0,j=0;
	/*while(i<n and j<m){
		if(a[i]>b[j]){
           v.push_back(b[j]);
		   j++;
		}
		else if(a[i]<b[j]){
			v.push_back(a[i]);
			i++;
		}
	}
	while(i<n){
		v.push_back(a[i]);
			i++;
	}
	while(j<m){
		 v.push_back(b[j]);
		   j++;
	}
	int n1=n+m;
	if(n1%2==1){
		return (double)v[n1/2];
	}
	double median= ((double)v[n1/2]+(double)v[(n1/2)-1])/2.0;
	return median;*/
	int size=n+m;
	int ind2=size/2;
	int ind1=ind2-1;
	int count=0;
	int inde1=-1,inde2=-1;
	while(i<n and j<m){
		if(a[i]<b[j]){
			if(count==ind1) inde1=a[i];
			if(count==ind2) inde2=a[i];
			count++;
			i++;
		}
		else{
			if(count==ind1) inde1=b[j];
			if(count==ind2) inde2=b[j];
			count++;
			j++;
		}
	}
	while(i<n){
		if(count==ind1) inde1=a[i];
			if(count==ind2) inde2=a[i];
			count++;
			i++;
	}
	while(j<m){
		if(count==ind1) inde1=b[j];
			if(count==ind2) inde2=b[j];
			count++;
			j++;
	}
	if(size%2==1){
		return (double)inde2;
	}
	return (double)((double)(inde1+inde2))/2.0;
}