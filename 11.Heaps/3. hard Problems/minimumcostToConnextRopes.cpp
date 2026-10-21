#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minCost(vector<int> &arr)
  {
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    while (pq.size() >= 2)
    {
      int f = pq.top();
      pq.pop();
      int s = pq.top();
      pq.pop();
      cost = cost + f + s;
      pq.push(f + s);
    }
    return cost;
  }
};