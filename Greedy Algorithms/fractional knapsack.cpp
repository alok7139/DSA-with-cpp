/*
You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.

Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.

Note:
You are allowed to break the items.
Example:
If 'N = 4' and 'W = 10'. The weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. 
Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. The total value of knapsack = 3 + 6 + 4 = 13.00   
*/
#include <bits/stdc++.h> 

  bool compare(pair<int, int> &a, pair<int, int> &b) {
    double x = double(a.second) / double(a.first);
    double y = double(b.second) / double(b.first);
    return x > y;
  };


double maximumValue(vector<pair<int, int>> &items, int n, int w) {
  // Write your code here.
  // ITEMS contains {weight, value} pairs.
  sort(items.begin(), items.end(), compare);
  int currweight = 0;
  double currvalue = 0;
  for (int i = 0; i < n; i++) {
    if (currweight + items[i].first <= w) {
      currweight += items[i].first;
      currvalue += items[i].second;
    } else {
      int remain = w - currweight;
      currvalue +=
          (double(items[i].second) / double(items[i].first)) * (double)remain;
      break;
    }
  }
  return currvalue;
}