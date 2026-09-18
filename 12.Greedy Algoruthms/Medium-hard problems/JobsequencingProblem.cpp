#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> parent;

  int find(int x)
  {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
  {
    int n = deadline.size();
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++)
      jobs.push_back({profit[i], deadline[i]});
    sort(jobs.rbegin(), jobs.rend());
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;
    int cnt = 0;
    int pro = 0;
    for (auto [p, d] : jobs)
    {

      d = min(d, n);
      int slot = find(d);
      if (slot > 0)
      {

        cnt++;
        pro += p;

        parent[slot] = find(slot - 1);
      }
    }

    return {cnt, pro};
  }
};
/*TC = O(n log n)
SC = O(n)*/