#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minPlatform(vector<int> &arr, vector<int> &dep)
  {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int n = arr.size();
    int m = dep.size();
    int i = 1, j = 0;
    int cnt = 1;
    int maxi = 1;
    while (i < n && j < m)
    {
      if (arr[i] <= dep[j])
      {
        cnt++;
        i++;
      }
      else
      {
        cnt--;
        j++;
      }
      maxi = max(maxi, cnt);
    }
    return maxi;
  }
};
/*TC = O(n)
SC = O(1)*/