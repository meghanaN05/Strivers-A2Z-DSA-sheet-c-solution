#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
      for (auto node : graph[i])
      {
        adj[node].push_back(i);
        indegree[i]++;
      }
    }

    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      cnt++;
      ans.push_back(node);
      for (int neigh : adj[node])
      {
        indegree[neigh]--;
        if (indegree[neigh] == 0)
          q.push(neigh);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};