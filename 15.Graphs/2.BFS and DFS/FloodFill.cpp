#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> row = {-1, 0, 1, 0};
  vector<int> col = {0, 1, 0, -1};
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    int prev = image[sr][sc];
    int n = image.size();
    int m = image[0].size();
    if (prev == color)
      return image;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;
    while (!q.empty())
    {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int nr = r + row[i];
        int nc = c + col[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == prev)
        {
          image[nr][nc] = color;
          q.push({nr, nc});
        }
      }
    }
    return image;
  }
};