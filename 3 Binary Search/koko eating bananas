/*
A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.



Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.



Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.



Example:

Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7

Output: 3

Explanation: If ‘m’ = 3, then 
The time taken to empty the 1st pile is 1 hour.
The time taken to empty the 2nd pile is 2 hour.
The time taken to empty the 3rd pile is 1 hour.
The time taken to empty the 4th pile is 3 hour.
Therefore a total of 7 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 7 hours.


*/
#include<bits/stdc++.h>
int maxifunc(vector<int>v,int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(maxi<v[i]){
            maxi=v[i];
        }
    }
    return maxi;
}
int calculatehrs(vector<int>v, int n, int h){
    int totalhrs=0;
    for(int i=0;i<n;i++){
        totalhrs += ceil((double)(v[i])/(double)(h));
    }
    return totalhrs;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
     int n=v.size(); 
      int maxi=maxifunc(v,n);

   // int ans=INT_MAX;
    int low=1,high=maxi;
    while(low<=high){
        int mid=(low+high)/2;
        int totalhrs=calculatehrs(v,n,mid);
        if(totalhrs<=h){
           // ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}