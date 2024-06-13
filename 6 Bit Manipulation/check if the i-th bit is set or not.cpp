/*
Given a number ‘N’ and a number ‘K’. Return true if ‘K’th bit of number is set, else return false.



Example:
Input: ‘N’ = 5, ‘K’ = 1

Output: YES

5 in binary can be written as 101 and as we can see a first bit from the right of 5 is set so the answer is 'YE

*/
bool isKthBitSet(int n, int k)
{
    // Write your code here.
    int binarynum[32];
    int i=0;
    while(n>0){
        binarynum[i]=n%2;
        n/=2;
        i++;
    }
    if(binarynum[k-1]==1){
        return true;
    }
    else{
        return false;
    }
}