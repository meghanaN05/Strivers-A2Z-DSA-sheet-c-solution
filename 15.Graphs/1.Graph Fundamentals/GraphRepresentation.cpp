// defination of graphs
#include <bits/stdc++.h>
using namespace std;
// adjacency list representation of graph
vector<vector<int>> adjList;
for (int i = 0; i < n; i++)
{
  int u, v;
  cin >> u >> v;
  adjList[u].push_back(v);
  adjList[v].push_back(u); // for undirected graph
}
// adjacency matrix representation of graph
vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
for (int i = 0; i < n; i++)
{
  int u, v;
  cin >> u >> v;
  adjMatrix[u][v] = 1;
  adjMatrix[v][u] = 1; // for undirected graph
}
