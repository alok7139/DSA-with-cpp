/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/
    bool static comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end){
                count++;
            }
            else{
                end=intervals[i][1];
            }
        }
        return count;
        
    }