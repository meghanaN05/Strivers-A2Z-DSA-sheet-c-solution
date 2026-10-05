#include <bits/stdc++.h>
using namespace std;
// bfs approach
class Solution
{
public:
  vector<int> row = {-1, 0, 1, 0};
  vector<int> col = {0, 1, 0, -1};
  int orangesRotting(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    int fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 2)
          q.push({i, j});
        if (grid[i][j] == 1)
          fresh++;
      }
    }
    int min = 0;
    while (fresh > 0 && !q.empty())
    {
      int size = q.size();
      while (size--)
      {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
          int nr = r + row[k];
          int nc = c + col[k];
          if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
          {
            grid[nr][nc] = 2;
            fresh--;
            q.push({nr, nc});
          }
        }
      }
      min++;
    }
    if (fresh > 0)
      return -1;
    return min;
  }
};
// dfs approach

class Solution
{
private:
  void dfs(vector<vector<int>> &grid, int r, int c, int time, vector<vector<int>> &rotTime)
  {
    int n = grid.size();
    int m = grid[0].size();

    // Direction vectors for 4-directional movement
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
      int nr = r + dr[i];
      int nc = c + dc[i];

      // Check boundary conditions and if it's a fresh orange
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
      {
        // If we found a faster way to rot this orange, update and recurse
        if (rotTime[nr][nc] > time + 1)
        {
          rotTime[nr][nc] = time + 1;
          dfs(grid, nr, nc, time + 1, rotTime);
        }
      }
    }
  }

public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    // Matrix to keep track of the minimum time at which an orange gets rotten
    vector<vector<int>> rotTime(n, vector<int>(m, INT_MAX));

    // 1. Start DFS from all initial rotten oranges (time = 0)
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 2)
        {
          rotTime[i][j] = 0;
          dfs(grid, i, j, 0, rotTime);
        }
      }
    }

    int maxMinutes = 0;

    // 2. Check the results: find max time or identify unreachable fresh oranges
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          if (rotTime[i][j] == INT_MAX)
          {
            return -1; // Fresh orange never got rotten
          }
          maxMinutes = max(maxMinutes, rotTime[i][j]);
        }
      }
    }

    return maxMinutes;
  }
};