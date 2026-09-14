#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> shortestPath(int V, vector<vector<int>> &edges)
  {
    vector<vector<pair<int, int>>> adj(V);
    vector<int> indegree(V, 0);
    for (auto &e : edges)
    {
      int u = e[0];
      int v = e[1];
      int wt = e[2];
      adj[u].push_back({v, wt});
      indegree[v]++;
    }
    queue<int> q;
    q.push(0);
    vcetor<int> dist(V, 1e9);
    dist[0] = 0;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }
    while (!q.empty())
    {
      int u = q.front();
      q, pop();
      for (auto &[v, wt] : adj[u])
      {
        if (dist[v] > dist[u] + wt)
        {
          dist[v] = dist[u] + wt;
        }
        indegree[v]--;
        if (indegree[v] == 0)
        {
          q.push(v);
        }
      }
    }
    for (int i = 0; i < V; i++)
    {
      if (dist[i] == 1e9)
        dist[i] = -1;
    }
    return dist;
  }
};
/*time complexity:O(V+E) && space complexity:O(V)*/