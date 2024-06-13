/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/
bool const compare(pair<int,int>&a,pair<int,int>b){
    return a.second<b.second;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n=start.size();
    vector<pair<int,int>>meet;
    for(int i=0;i<n;i++){
        meet.push_back({start[i],end[i]});
    }
    sort(meet.begin(),meet.end(),compare);
    int count=1;
    int endmeet=meet[0].second;
    for(int i=1;i<n;i++){
        if(endmeet<meet[i].first){
            count++;
            endmeet=meet[i].second;
        }
    }
    return count;
     
}