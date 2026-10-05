#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{
  visited[s] = true;
  res.push_back(s);

  // Recursively visit all adjacent
  // vertices that are not visited yet
  for (int i : adj[s])
  {
    if (!visited[i])
    {
      dfs(adj, visited, i, res);
    }
  }
}

vector<vector<int>> getComponents(vector<vector<int>> &adj)
{
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<vector<int>> res;

  // Loop through all vertices
  // to handle all components
  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      vector<int> component;
      dfs(adj, visited, i, component);
      res.push_back(component);
    }
  }

  return res;
}
//// BFS for a single connected component
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

// BFS for all components (handles disconnected graphs)
vector<vector<int>> getComponents(vector<vector<int>> &adj)
{
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<vector<int>> res;

  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      vector<int> component;
      bfs(adj, i, visited, component);
      res.push_back(component);
    }
  }
  return res;
}
