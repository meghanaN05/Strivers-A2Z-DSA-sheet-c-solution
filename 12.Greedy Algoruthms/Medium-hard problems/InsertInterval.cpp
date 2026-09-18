#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    intervals.push_back(newInterval);
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
      if (ans.back()[1] >= intervals[i][0])
      {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
      else
      {
        ans.push_back(intervals[i]);
      }
    }
    return ans;
  }
};
/*TC = O(n log n)
SC = O(1)*/