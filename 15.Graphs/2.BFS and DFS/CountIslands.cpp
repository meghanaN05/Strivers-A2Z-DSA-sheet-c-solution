#include <vector>
using namespace std;
class Solution
{
private:
  void dfs(int r, int c, vector<vector<char>> &grid, int n, int m)
  {
    // Mark current cell as visited by converting 'L' to 'W'
    grid[r][c] = 'W';

    // 8 direction vectors (up, down, left, right, and 4 diagonals)
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i)
    {
      int nr = r + dr[i];
      int nc = c + dc[i];

      // Check boundaries and if the adjacent cell is land ('L')
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 'L')
      {
        dfs(nr, nc, grid, n, m);
      }
    }
  }

public:
  int countIslands(vector<vector<char>> &grid)
  {
    int n = grid.size();
    if (n == 0)
      return 0;
    int m = grid[0].size();

    int islandCount = 0;

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        // When land ('L') is found, trigger DFS and increment count
        if (grid[i][j] == 'L')
        {
          islandCount++;
          dfs(i, j, grid, n, m);
        }
      }
    }

    return islandCount;
  }
};