#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> rows = {-1, 0, 1, 0};
  vector<int> cols = {0, 1, 0, -1};
  void dfs(int i, int j, vector<vector<int>> &board)
  {
    int n = board.size();
    int m = board[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 1)
      return;
    board[i][j] = 0;
    for (int k = 0; k < 4; k++)
    {
      int ni = i + rows[k];
      int nj = j + cols[k];
      dfs(ni, nj, board);
    }
  }
  int numEnclaves(vector<vector<int>> &board)
  {
    int n = board.size();
    int m = board[0].size();
    if (n == 0 || m == 0)
      return 0;
    for (int i = 0; i < n; i++)
    {
      dfs(i, 0, board);
      dfs(i, m - 1, board);
    }
    for (int i = 0; i < m; i++)
    {
      dfs(0, i, board);
      dfs(n - 1, i, board);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (board[i][j] == 1)
          cnt++;
      }
    }
    return cnt;
  }
};