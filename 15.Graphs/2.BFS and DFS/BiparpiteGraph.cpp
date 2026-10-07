#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // bfs approach
  bool bfs(int i, vector<vector<int>> &graph, vector<int> color)
  {
    color[i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      for (int neigh : graph[node])
      {
        if (color[neigh] == -1)
        {
          color[neigh] = 1 - color[node];
          q.push(neigh);
        }
        else if (color[neigh] == color[node])
          return false;
      }
    }
    return true;
  }
  bool isBipartite(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
      if (color[i] == -1)
      {
        if (!bfs(i, graph, color))
          return false;
      }
    }
    return true;
  }
};