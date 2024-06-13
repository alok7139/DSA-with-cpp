/*
You are given an array of size ‘N’ which is an array representation of min-heap.



You need to convert this min-heap array representation to a max-heap array representation. Return the max-heap array representation.



For Example
Corresponding to given min heap : [1,2,3,6,7,8]

It can be converted to the following max heap: [8,7,3,6,2,1]
*/
void maxheap(vector<int>&ans, int data ,int n){
	ans.push_back(data);
	int index=ans.size()-1;
	while(index>0){
		int parent=(index-1)/2;
		if(ans[index]>ans[parent]){
			swap(ans[index],ans[parent]);
			index=parent;
		}
		else{
			break;
		}
	}
}
vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Write your code here.
	// priority_queue<int>pq;
	// for(int i=0;i<n;i++){
	// 	pq.push(arr[i]);
	// }
	// vector<int>ans;
	// while(!pq.empty()){
	// 	ans.push_back(pq.top()); 
	// 	pq.pop();
	// }
	// return ans;

	vector<int>ans;
	for(int i=0;i<n;i++){
		maxheap(ans,arr[i],n);
	}
	return ans;
	
}