#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &e : times)
    {
      int u = e[0];
      int v = e[1];
      int t = e[2];
      adj[u].push_back({v, t});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    vector<int> dist(n + 1, 1e9);
    dist[k] = 0;
    while (!pq.empty())
    {
      int time = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      if (time > dist[node])
        continue;
      for (auto &it : adj[node])
      {
        int adjNode = it.first;
        int t = it.second;
        if (t + time < dist[adjNode])
        {
          dist[adjNode] = t + time;
          pq.push({t + time, adjNode});
        }
      }
    }
    int ans = *max_element(dist.begin() + 1, dist.end());
    if (ans == 1e9)
      return -1;
    return ans;
  }
};