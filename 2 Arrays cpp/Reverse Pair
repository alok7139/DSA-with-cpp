/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1


*/
void merge(vector <int> & skill, int low ,int mid, int high){
    int l=low,r=mid+1;
    vector<int>v;
    while(l<=mid and r<=high){
        if(skill[l]<=skill[r]){
            v.push_back(skill[l]);
            l++;
        }
        else{
            v.push_back(skill[r]);
            r++;
        }
    }
    while(l<=mid){
       v.push_back(skill[l]);
            l++; 
    }
    while(r<=high){
        v.push_back(skill[r]);
            r++;
    }
    for(int i=low;i<=high;i++){
        skill[i]=v[i-low];
    }
}
int countpairs(vector<int>&arr,int low, int mid, int high){
    int right=mid+1;
    int count=0;
    for(int i=low;i<=mid;i++){
        while(right<=high and arr[i]>2*arr[right]){
            right++;
        }
          count += right-(mid+1);
    }
    return count;
}
int merge(vector <int> & skill, int low, int high){
    int count=0;
    if(low>=high){
        return count;
    }
    int mid=(low+high)/2;
    count += merge(skill,low,mid);
    count += merge(skill,mid+1,high);
    count += countpairs(skill,low,mid,high);
    merge(skill,low,mid,high);
    return count;
}
int team(vector <int> & skill, int n)
{
    
    return merge(skill,0,n-1);
}