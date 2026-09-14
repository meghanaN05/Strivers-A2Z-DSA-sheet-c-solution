#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
  {
    vector<vector<int>> adj(V);
    for (auto &e : edges)
    {
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    queue<int> q;
    q.push(src);
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      if (u == dest)
        return dist[u];
      for (auto v : adj[u])
      {
        if (dist[v] == 1e9)
        {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    return -1;
  }
};
/* time complexity: O(V + E), space complexity: O(V) */