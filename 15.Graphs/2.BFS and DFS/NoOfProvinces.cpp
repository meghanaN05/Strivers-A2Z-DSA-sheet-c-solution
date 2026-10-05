#include <bits/stdc++.h>
using namespace std;
// dfs approach
class Solution
{
public:
  void dfs(int i, vector<int> &vis, vector<vector<int>> &isConnected)
  {
    vis[i] = 1;
    for (int j = 0; j < isConnected.size(); j++)
    {
      if (isConnected[i][j] == 1 && !vis[j])
        dfs(j, vis, isConnected);
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    vector<int> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
      if (!vis[i])
        cnt++;
      dfs(i, vis, isConnected);
    }
    return cnt;
  }
};
// bfs approaach
int findCircleNum(vector<vector<int>> &isConnected)
{
  int n = isConnected.size();
  vector<int> vis(n, 0);
  int cnt = 0;
  for (int i = 0; i < isConnected.size(); i++)
  {
    if (!vis[i])
    {
      cnt++;
      queue<int> q;
      q.push(i);
      vis[i] = 1;
      while (!q.empty())
      {
        int node = q.front();
        q.pop();
        for (int j = 0; j < isConnected.size(); j++)
        {
          if (isConnected[node][j] == 1 && !vis[j])
          {
            q.push(j);
            vis[j] = 1;
          }
        }
      }
    }
  }
  return cnt;
}