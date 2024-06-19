/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= values of POINTS arrays <= 100 .

Time limit: 1 sec
Sample Input 1:
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
Sample Output 1:
11
210
Explanation of sample input 1:
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points. 
On the second day, Ninja will do running and earn 3 merit points. 
On the third day, Ninja will do fighting and earn 3 merit points. 
The total merit point is 11 which is the maximum. 
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points. 
On the second day, Ninja will do fighting and earn 50 merit points. 
On the third day, Ninja will learn new moves and earn 90 merit points. 
The total merit point is 210 which is the maximum. 
Hence, the answer is 210
*/

#include<bits/stdc++.h>


int f(int day,int lasttask,vector<vector<int>> &points,vector<vector<int>>&dp){
    // memoization method
    // base case if day is given only 1
    if(day==0){
        int maxi=0;
        for(int task=0;task<=2;task++){
            if(task!=lasttask){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][lasttask]!=-1){
        return dp[day][lasttask];
    }
   int maxi=0;
   int activity=0;
    for(int task=0;task<=2;task++){
        if(task!=lasttask){
             activity = points[day][task] + f(day-1,task,points,dp);
            // maxi = max(maxi,activity);
        }
           maxi = max(maxi,activity);

    }
    return dp[day][lasttask] = maxi;


}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write ur code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);

    // tabulation method
//     dp[0][0]=max(points[0][1],points[0][2]);
//     dp[0][1]=max(points[0][0],points[0][2]);
//     dp[0][2]=max(points[0][1],points[0][0]);
//     dp[0][3]=max(points[0][0],max(points[0][2],points[0][1]));



//    // lasttask will be 0,1,2,3 and in 3 day the answer will we store in maxmium
//     for(int day =1;day<n;day++){
//         for(int lasttask=0;lasttask<=3;lasttask++){
//             dp[day][lasttask]=0;
//             for(int task=0;task<=2;task++){
//                 if (task != lasttask) {
//                   int activity = points[day][task] + dp[day - 1][task];
//                   dp[day][lasttask] = max(dp[day][lasttask], activity);
//                 }
//             }
//         }
//     }
//    return dp[n-1][3];
}