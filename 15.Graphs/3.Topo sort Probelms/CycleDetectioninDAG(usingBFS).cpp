#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isCyclic(int V, vector<vector<int>> &edges)
  {
    vector<vector<int>> adj(V);
    for (auto &e : edges)
    {
      adj[e[0]].push_back(e[1]);
    }
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
      for (int neigh : adj[i])
      {
        indegree[neigh]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }
    int cnt = 0;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      cnt++;
      for (int neigh : adj[node])
      {
        indegree[neigh]--;
        if (indegree[neigh] == 0)
          q.push(neigh);
      }
    }

    if (cnt == V)
      return false;
    return true;
  }
};