/*
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
    int countPrimes(int n) {
        if(n<=1){
            return 0;
        }
        int count=0;
        vector<bool>dp(n+1,false);
        dp[0]=dp[1]=1;
        for(int i=2;i*i<(n);i++){
            if(dp[i]==0){
                for(int j=i*i;j<=n;j+=i){
                    dp[j]=1;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(!dp[i]){
                count++;
            }
        }
        return count;

        
    }