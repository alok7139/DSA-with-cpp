/*
For a given integer 'N', you have to return the number of set bits in the binary representation of the numbers from 1 to 'N'.



In a binary number '1' is considered as a set bit and '0' as not set.



Example:
If 'N' is 4, then

1 has a binary representation of 1
2 has a binary representation of 10
3 has a binary representation of 11
4 has a binary representation of 100

Hence number of set bits is 5.
*/
#include <bits/stdc++.h>
int bits(int n){
    int binary[32];
    int i=0;
    while(n){
        binary[i]=n%2;
        n/=2;
        i++;
    }
    int count=0;
    for(int j=i-1;j>=0;j--){
        if(binary[j]==1){
            count++;
        }
    }
    return count;
}
int powerof2(int n){
    long x = 0;
    while((1<<x)<=n){
        x++;
    }
    return x-1;
}
int countSetBits(int n)
{
    //Write your code here

    // brute method
    //   vector<int>ans;
    //   for(int i=1;i<=n;i++){
    //       int sum = 0;
    //       int num = i;
    //       while(num){
    //           sum += num%2;
    //           num /= 2;
    //       }
    //       ans.push_back(sum);
    //   }
    //   int count = accumulate(ans.begin(),ans.end(),0);
    //   return count;
    if(n==0){
        return 0;
    }

    int x = powerof2(n);
    int y = x*(1<<(x-1));
    int z = n-(1<<x);
    return y+z+1+countSetBits(z);
        
    
}