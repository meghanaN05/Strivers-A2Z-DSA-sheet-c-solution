#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    vector<vector<pair<int, int>>> adj(n);
    for (auto &e : flights)
    {
      int u = e[0];
      int v = e[1];
      int wt = e[2];
      adj[u].push_back({v, wt});
    }
    queue<pair<int, pair<int, int>>> q;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    q.push({0, {src, 0}});
    while (!q.empty())
    {
      int stop = q.front().first;
      int node = q.front().second.first;
      int cost = q.front().second.second;
      q.pop();
      if (stop > k)
        continue;
      for (auto &it : adj[node])
      {
        int adjNode = it.first;
        int edw = it.second;
        if (cost + edw < dist[adjNode] && stop <= k)
        {
          dist[adjNode] = cost + edw;
          q.push({stop + 1, {adjNode, cost + edw}});
        }
      }
    }
    if (dist[dst] == 1e9)
      return -1;
    return dist[dst];
  }
};