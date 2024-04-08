/*
Given an infinite supply of Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins and an amount 'N'.



Find the minimum coins needed to make the sum equal to 'N'. You have to return the list containing the value of coins required in decreasing order.



For Example
For Amount = 70, the minimum number of coins required is 2 i.e an Rs. 50 coin and a Rs. 20 coin.
Note
It is always possible to find the minimum number of coins for the given amount. So, the answer will always exist.
*/
vector<int> MinimumCoins(int k)
{
    // Write your code here
    vector<int> v =  {1, 2, 5, 10, 20, 50, 100, 500, 1000} ;
    int m=v.size();
    vector<int>ans;
    for(int i=m-1;i>=0;i--){
        while(v[i]<=k){
           ans.push_back(v[i]);
           k=k-v[i];
        }
    }
    return ans;
    
}