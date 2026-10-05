#include <bits/stdc++.h>
using namespace std;
// dfs approach
class Solution
{
public:
  void dfs(int it, int &edges, int &node, vector<int> &vis, vector<vector<int>> &adj)
  {
    vis[it] = 1;
    node++;
    for (auto &i : adj[it])
    {
      edges++;
      if (!vis[i])
        dfs(i, edges, node, vis, adj);
    }
  }
  int countCompleteComponents(int n, vector<vector<int>> &edges)
  {
    int cnt = 0;
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        int edge = 0;
        int nodes = 0;
        dfs(i, edge, nodes, vis, adj);
        if (edge == nodes * (nodes - 1))
          cnt++;
      }
    }
    return cnt;
  }
  // bfs approach
  int countCompleteComponents(int n, vector<vector<int>> &edges)
  {
    int cnt = 0;
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        int edge = 0;
        int nodes = 0;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
          int node = q.front();
          q.pop();
          nodes++;
          for (auto &it : adj[node])
          {
            edge++;
            if (!vis[it])
            {
              vis[it] = 1;
              q.push(it);
            }
          }
        }
        if (edge == nodes * (nodes - 1))
          cnt++;
      }
    }
    return cnt;
  }
};