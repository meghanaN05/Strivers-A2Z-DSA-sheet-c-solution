#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // binary search approach
  vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
  {
    int maxi = 0;
    int row = 0;
    int m = mat[0].size();
    for (int i = 0; i < mat.size(); i++)
    {
      sort(mat[i].begin(), mat[i].end());
      int l = 0, r = mat[0].size() - 1;
      int ans = m;
      int cnt = 0;
      while (l <= r)
      {
        int mid = l + (r - l) / 2;
        if (mat[i][mid] == 1)
        {
          ans = mid;
          r = mid - 1;
        }
        else
        {
          l = mid + 1;
        }
      }
      cnt = m - ans;
      if (cnt > maxi)
      {
        maxi = cnt;
        row = i;
      }
    }

    vector<int> ans(2);
    ans[0] = row;
    ans[1] = maxi;
    return ans;
  }
};