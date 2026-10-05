#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> row = {-1, 0, 1, 0};
  vector<int> col = {0, 1, 0, -1};
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mat[i][j] == 0)
          q.push({i, j});
        else
          mat[i][j] = INT_MAX;
      }
    }
    while (!q.empty())
    {
      auto [r, c] = q.front();
      q.pop();
      for (int k = 0; k < 4; k++)
      {
        int nr = r + row[k];
        int nc = c + col[k];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m)
        {
          if (mat[nr][nc] > mat[r][c] + 1)
          {
            mat[nr][nc] = mat[r][c] + 1;
            q.push({nr, nc});
          }
        }
      }
    }
    return mat;
  }
};