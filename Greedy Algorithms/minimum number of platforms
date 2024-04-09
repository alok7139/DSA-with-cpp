/*
You have been given two arrays, 'AT' and 'DT', representing the arrival and departure times of all trains that reach a railway station.

Your task is to find the minimum number of platforms required for the railway station so that no train needs to wait.

Note :
1. Every train will depart on the same day and the departure time will always be greater than the arrival time. For example, A train with arrival time 2240 and departure time 1930 is not possible.

2. Time will be given in 24H format and colons will be omitted for convenience. For example, 9:05AM will be given as "905", or 9:10PM will be given as "2110".

3. Also, there will be no leading zeroes in the given times. For example, 12:10AM will be given as “10” and not as “0010”.
Sample Input 1:
2
6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000
4
100 200 300 400
200 300 400 500
Sample Output 1:
3
2
Explanation of the Sample Output 1:
In test case 1, For the given input, the following will be the schedule of the trains:

Train 1 arrived at 900 on platform 1. 
Train 1 departed at 910 from platform 1. 
Train 2 arrived at 940 on platform 1.
Train 3 arrived at 950 on platform 2 (since platform 1 was already occupied by train 1).
Train 4 arrived at 1100 on platform 3 (since both platforms 1 and 2 were occupied by trains 2 and 3 respectively).
Train 3 departed at 1120 from platform 2 (platform 2 becomes vacant).
Train 4 departed at 1130 from platform 3 (platform 3 also becomes vacant).
Train 2 departed at 1200 from platform 1 (platform 1 also becomes vacant).
Train 5 arrived at 1500 on platform 1.
Train 6 arrived at 1800 on platform 2.
Train 5 departed at 1900 from platform 1.
Train 6 departed at 2000 from platform 2.

Thus, minimum 3 platforms are needed for the given input.

In test case 2, For the given input, the following will be the schedule of the trains:

Train 1 arrived at 100 on platform 1. 
Train 2 arrived at 200 from platform 2 (as platform 1 is occupied by train 1).
Train 1 departed at 200 from platform 1. 
Train 3 arrived at 300 on platform 1.
Train 2 departed at 300 from platform 2.
Train 4 arrived at 400 on platform 2.
Train 3 departed at 400 from platform 1.
Train 4 departed at 500 from platform 2. 

Thus, 2 platforms are needed for the given input.
*/
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    // int platform=1;
    // for(int i=0;i<n;i++){
    //     int count=1;
    //     for(int j=i+1;j<n;j++){
    //         if((at[i]>=at[j] and at[i]<=dt[j]) or (at[j]>=at[i] and at[j]<=dt[i])){
    //             count++;
    //         }
    //     }
    //     platform = max(platform,count);
    // }
    // return platform;
    int platform=1,count=1;
    int i=0,j=1;
    while(i<n and j<n){
        if(dt[i]>=at[j]){
            count++;
            j++;
        }
        else{
            count--;
            i++;
        }
        platform=max(platform,count);
    }
    return platform;
}