/*
Given that integers are read from a data stream. Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.
*/
#include <bits/stdc++.h>
int signum(int a,int b){
	if(a==b){
		return 0;
	}
	 if(a>b){
		return 1;
	}
	if(a<b){
		return -1;
	}
}
void call(priority_queue<int>&maxpq,priority_queue<int,vector<int>,greater<int>>&minpq,int data,int& median){
	switch(signum(maxpq.size(),minpq.size())){
		case 0:
		if(data>median){
			minpq.push(data);
			median=minpq.top();
		}
		else{
			maxpq.push(data);
			median=maxpq.top();
		}
		break;

		case 1:
		if(data>median){
			minpq.push(data);
		}
		else{
			minpq.push(maxpq.top());
			maxpq.pop();
			maxpq.push(data);
		}
		median=(maxpq.top()+minpq.top())/2;
        break;

        case -1:
		if(data>median){
			maxpq.push(minpq.top());
			minpq.pop();
			minpq.push(data);
		}
		else{
			maxpq.push(data);
		}
		median=(maxpq.top()+minpq.top())/2;
		break;
	}
};





vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int>maxpq;
	priority_queue<int,vector<int>,greater<int>>minpq;
	vector<int>ans;
	int median=0;
	for(int i=0;i<n;i++){
		call(maxpq,minpq,arr[i],median);
		ans.push_back(median);
	}
	return ans;
	
}