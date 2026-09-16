#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
  {
    int n = val.size();
    vector<pair<double, pair<int, int>>> a;
    for (int i = 0; i < n; i++)
    {
      double ratio = ((double)val[i]) / ((double)wt[i]);
      a.push_back({ratio, {wt[i], val[i]}});
    }
    sort(a.begin(), a.end(), [](auto &a, auto &b)
         { return a.first > b.first; });
    double total = 0.0;
    int remaining = capacity;
    for (auto it : a)
    {
      int w = it.second.first;
      int v = it.second.second;
      double r = it.first;
      if (remaining >= w)
      {
        total += v;
        remaining -= w;
      }
      else
      {
        total += remaining * r;
        break;
      }
    }
    return total;
  }
};

/*time complexity: O(nlogn) && space complexity o(n)*/
