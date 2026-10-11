#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> kahnAlgorithm(int V, vector<vector<int>> &edges)
  {
    int n = V;
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
    }
    vector<int> indegree(n, 0);
    queue<int> q;
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int neigh : adj[i])
      {
        indegree[neigh]++;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for (int neigh : adj[node])
      {
        indegree[neigh]--;
        if (indegree[neigh] == 0)
          q.push(neigh);
      }
    }
    return ans;
  }
};