#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // using sets instead of priority_queue{not expected in the interview because it is slow compared to pq since tc:o(n*m)log(n*m),sc:o(n*m)}
  vector<int> dr = {1, 0, -1, 0};
  vector<int> dc = {0, 1, 0, -1};
  int minimumEffortPath(vector<vector<int>> &heights)
  {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {0, 0}});
    dist[0][0] = 0;
    while (!st.empty())
    {
      auto it = *st.begin();
      st.erase(st.begin());
      int wt = it.first;
      int r = it.second.first;
      int c = it.second.second;
      if (r == n - 1 && c == m - 1)
        return wt;
      for (int i = 0; i < 4; i++)
      {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m)
        {
          int newwt = max(wt, abs(heights[nr][nc] - heights[r][c]));
          if (newwt < dist[nr][nc])
          {
            if (dist[nr][nc] != INT_MAX)
              st.erase({dist[nr][nc], {nr, nc}});
            dist[nr][nc] = newwt;
            st.insert({dist[nr][nc], {nr, nc}});
          }
        }
      }
    }
    return 0;
  }
};