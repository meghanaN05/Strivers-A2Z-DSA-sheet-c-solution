#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
  {
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    priority_queue<tuple<int, int, int>> pq;
    set<pair<int, int>> vis;
    pq.push({a[0] + b[0], 0, 0});
    vis.insert({0, 0});
    vector<int> ans;
    while (k-- && !pq.empty())
    {
      auto [sum, i, j] = pq.top();
      pq.pop();
      ans.push_back(sum);
      if (i + 1 < a.size() && vis.find({i + 1, j}) == vis.end())
      {
        pq.push({a[i + 1] + b[j], i + 1, j});
        vis.insert({i + 1, j});
      }

      if (j + 1 < b.size() && vis.find({i, j + 1}) == vis.end())
      {
        vis.insert({i, j + 1});
        pq.push({a[i] + b[j + 1], i, j + 1});
      }
    }

    return ans;
  }
};