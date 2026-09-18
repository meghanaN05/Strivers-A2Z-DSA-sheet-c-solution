#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int countPaths(int n, vector<vector<int>> &roads)
  {
    const int mod = 1e9 + 7;
    vector<pair<int, int>> adj[n];
    for (auto &e : roads)
    {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    vector<long long> dist(n, 1e18);
    vector<long long> ways(n, 0);
    set<pair<long long, int>> st;
    dist[0] = 0;
    ways[0] = 1;
    st.insert({0, 0});
    while (!st.empty())
    {
      auto it = *st.begin();
      st.erase(it);
      long long d = it.first;
      int node = it.second;
      for (auto &p : adj[node])
      {
        int nbr = p.first;
        long long wt = p.second;
        if (d + wt < dist[nbr])
        {
          if (dist[nbr] != 1e18)
            st.erase({dist[nbr], nbr});
          dist[nbr] = d + wt;
          ways[nbr] = ways[node] % mod;
          st.insert({dist[nbr], nbr});
        }
        else if (d + wt == dist[nbr])
        {
          ways[nbr] = (ways[nbr] + ways[node]) % mod;
        }
      }
    }

    return ways[n - 1] % mod;
  }
};