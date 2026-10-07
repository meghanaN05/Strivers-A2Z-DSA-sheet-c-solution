#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
  void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &vis,
           vector<pair<int, int>> &shape, int baseR, int baseC)
  {
    int n = grid.size();
    int m = grid[0].size();

    vis[r][c] = true;
    shape.push_back({r - baseR, c - baseC});

    // 4 direction vectors: Up, Right, Down, Left
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
          !vis[nr][nc] && grid[nr][nc] == 'L')
      {
        dfs(nr, nc, grid, vis, shape, baseR, baseC);
      }
    }
  }

public:
  int countDistinctIslands(vector<vector<char>> &grid)
  {
    int n = grid.size();
    if (n == 0)
      return 0;
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> uniqueIslands;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vis[i][j] && grid[i][j] == 'L')
        {
          vector<pair<int, int>> shape;
          dfs(i, j, grid, vis, shape, i, j);
          uniqueIslands.insert(shape);
        }
      }
    }

    return uniqueIslands.size();
  }
};