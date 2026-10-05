#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, int src, vector<bool> &visited, vector<int> &res)
{
  queue<int> q;
  visited[src] = true;
  q.push(src);

  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    res.push_back(curr);

    // visit all the unvisited
    // neighbours of current node
    for (int x : adj[curr])
    {
      if (!visited[x])
      {
        visited[x] = true;
        q.push(x);
      }
    }
  }
}