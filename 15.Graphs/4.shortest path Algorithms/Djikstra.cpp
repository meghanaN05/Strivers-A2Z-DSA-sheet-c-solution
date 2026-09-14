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
    set<pair<int, int>> st;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    st.insert({0, src});
    while (!st.empty())
    {
      auto it = *st.begin();
      int dis = it.first;
      int node = it.second;
      st.erase(it);
      for (auto nbr : adj[node])
      {
        int adjNode = nbr.first;
        int wt = nbr.second;
        if (dis + wt < dist[adjNode])
        {
          if (dist[adjNode] != INT_MAX)
            st.erase({dist[adjNode], adjNode});
          dist[adjNode] = dis + wt;
          st.insert({dist[adjNode], adjNode});
        }
      }
    }

    return dist;
  }
};
/*time complexity :O(ElogV) && space complexity:O(V+E)*/