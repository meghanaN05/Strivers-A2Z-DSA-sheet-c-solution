#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> maxMeetings(vector<int> &s, vector<int> &f)
  {
    vector<pair<pair<int, int>, int>> meetings;
    for (int i = 0; i < s.size(); i++)
      meetings.push_back({{f[i], i + 1}, s[i]});
    sort(meetings.begin(), meetings.end());
    vector<int> ans;
    int lastFinish = -1;
    for (auto &x : meetings)
    {
      int finish = x.first.first;
      int index = x.first.second;
      int start = x.second;
      if (start > lastFinish)
      {
        ans.push_back(index);
        lastFinish = finish;
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
/*TC = O(n log n)
SC = O(n)*/
