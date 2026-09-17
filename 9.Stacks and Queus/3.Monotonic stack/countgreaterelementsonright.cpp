#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> count_NGE(vector<int> &arr, vector<int> &indices)
  {
    int n = arr.size();
    vector<int> ans(indices.size());
    for (int i = 0; i < indices.size(); i++)
    {
      int idx = indices[i];
      int x = arr[idx];
      int cnt = 0;
      for (int j = idx + 1; j < n; j++)
      {
        if (arr[j] > x)
          cnt++;
      }

      ans[i] = cnt;
    }

    return ans;
  }
};
/*time complexity: O(n*m), where n is the size of arr and m is the size of indices*/
/*space complexity: O(1)*/