#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    // code here
    unordered_map<int, int> mp;
    for (auto x : nums)
      mp[x]++;
    priority_queue<pair<int, int>> pq;
    for (auto x : mp)
    {
      pq.push({x.second, x.first});
    }
    vector<int> ans;
    while (!pq.empty() && k--)
    {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    return ans;
  }
};