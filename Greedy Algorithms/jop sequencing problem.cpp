/*
You are given a 'Nx3' 2-D array 'Jobs' describing 'N' jobs where 'Jobs[i][0]' denotes the id of 'i-th' job, 'Jobs[i][1]' denotes the deadline of 'i-th' job, and 'Jobs[i][2]' denotes the profit associated with 'i-th job'.



You will make a particular profit if you complete the job within the deadline associated with it. Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.



Return the number of jobs to be done to get maximum profit.



Note :
If a particular job has a deadline 'x', it means that it needs to be completed at any time before 'x'.

Assume that the start time is 0.


For Example :
'N' = 3, Jobs = [[1, 1, 30], [2, 3, 40], [3, 2, 10]].

All the jobs have different deadlines. So we can complete all the jobs.

At time 0-1, Job 1 will complete.
At time 1-2, Job 3 will complete.
At time 2-3, Job 2 will complete.

So our answer is [3 80].

*/
#include <bits/stdc++.h>
bool  comp(vector<int>&a,vector<int>&b){
    return a[2]>b[2];
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    // vector<int>ans;
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),comp);
    int maxi=jobs[0][1];
    for(int i=0;i<n;i++){
        maxi=max(maxi,jobs[i][1]);
    }
    int slot[maxi+1];
    for(int i=0;i<=maxi;i++){
        slot[i]=-1;
    }
    int profit=0,countjob=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i][1];j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                profit += jobs[i][2];
                countjob++;
                break;
            }
        }
    }
    return {countjob,profit};
}