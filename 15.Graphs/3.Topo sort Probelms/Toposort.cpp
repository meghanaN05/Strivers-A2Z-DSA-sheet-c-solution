#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
  {
    vis[node] = 1;
    for (auto &it : adj[node])
    {
      if (!vis[it])
      {
        dfs(it, adj, vis, st);
      }
    }
    st.push(node);
  }
  vector<int> topoSort(int V, vector<vector<int>> &edges)
  {
    vector<vector<int>> adj(V);
    vector<int> vis(V, 0);
    for (auto &it : edges)
    {
      int u = it[0];
      int v = it[1];
      adj[u].push_back(v);
    }
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
        dfs(i, adj, vis, st);
    }
    vector<int> ans;
    while (!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }
    return ans;
  }
};