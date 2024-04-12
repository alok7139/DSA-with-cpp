/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>v;
        // int n=intervals.size();
        // int m=intervals[0].size();
        for(auto currintervals:intervals){
            if(newInterval[0]>currintervals[1]){
                   v.push_back(currintervals);
            }
            else if(newInterval[1] < currintervals[0]){
                v.push_back(newInterval);
                newInterval=currintervals;
            }
            else{
                newInterval[0]=min(newInterval[0],currintervals[0]);
                newInterval[1]=max(newInterval[1],currintervals[1]);
            }
        }
        v.push_back(newInterval);
        return v;
    }