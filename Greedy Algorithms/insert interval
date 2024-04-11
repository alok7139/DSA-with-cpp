/*
You are given a 2-dimensional array ‘Intervals’ containing a list of non-overlapping intervals sorted by their start time. You are given an interval ‘newInterval’. Your task is to insert the given interval at the correct position and merge all necessary intervals to produce a list with only mutually exclusive intervals.

For Example:
Consider 'Intervals' = [[1, 3], [5, 7], [8, 12]], and 'newInterval' = [4, 6] 
The interval [4, 6] overlaps with [5, 7]. Therefore we can merge the intervals and produce an interval [4, 7]. Hence the answer [[1,3], [4,7], [8,12]]
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
0 <= N <= 10^5
0 <= Intervals[i][0], Intervals[i][1] <= 10^10
0 <= newInterval[0], newInterval[1] <= 10^10

Time Limit: 1 sec
*/
vector<vector<int>> addInterval(vector<vector<int>> &intervals, int n, vector<int> &newInterval)
{
    // Write your code here
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