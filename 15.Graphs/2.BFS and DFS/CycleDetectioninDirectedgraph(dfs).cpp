#include <bits/stdc++.h>
using namespace std;


using namespace std;

class Graph
{
private:
  bool dfsCheck(int node, vector<bool> &vis, vector<bool> &pathVis)
  {
    vis[node] = true;
    pathVis[node] = true; // Mark node as part of current recursion stack

    // Traverse adjacent nodes
    for (int neighbor : adj[node])
    {
      // Case 1: Neighbor is not visited yet
      if (!vis[neighbor])
      {
        if (dfsCheck(neighbor, vis, pathVis))
        {
          return true;
        }
      }
      // Case 2: Neighbor is visited AND is in the current recursion stack -> Cycle found!
      else if (pathVis[neighbor])
      {
        return true;
      }
    }

    pathVis[node] = false;
    return false;
  }

public:
  bool isCyclic()
  {
    vector<bool> vis(V, false);
    vector<bool> pathVis(V, false);

    // Check for cycle in each component (handles disconnected graphs)
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfsCheck(i, vis, pathVis))
        {
          return true;
        }
      }
    }
    return false;
  }
};
