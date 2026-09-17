#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // bfs approach
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    queue<pair<int, int>> q;
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return -1;
    int path = 1;
    q.push({0, 0});
    grid[0][0] = 1;
    while (!q.empty())
    {
      int size = q.size();
      for (int x = 0; x < size; x++)
      {
        auto [r, c] = q.front();
        q.pop();
        if (r == n - 1 && c == n - 1)
          return path;
        for (int i = 0; i < 8; i++)
        {
          int nr = r + dx[i];
          int nc = c + dy[i];
          if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0)
          {
            grid[nr][nc] = 1;
            q.push({nr, nc});
          }
        }
      }
      path++;
    }
    return -1;
  }
};
/*time complexity:0(n^2) && space complexity:O(n^2)*/