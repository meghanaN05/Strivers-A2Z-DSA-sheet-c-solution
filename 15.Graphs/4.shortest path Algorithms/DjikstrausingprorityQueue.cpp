#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
  {
    vector<vector<pair<int, int>>> adj(V);
    for (auto &e : edges)
    {
      int u = e[0];
      int v = e[1];
      int wt = e[2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
      auto it = pq.top();
      pq.pop();
      int dis = it.first;
      int node = it.second;
      if (dis > dist[node])
        continue;

      for (auto nbr : adj[node])
      {
        int adjNode = nbr.first;
        int wt = nbr.second;
        if (dis + wt < dist[adjNode])
        {
          dist[adjNode] = dis + wt;
          pq.push({dist[adjNode], adjNode});
        }
      }
    }

    return dist;
  }
};
/*time complexity :O(ElogV) && space complexity:O(V+E)*/