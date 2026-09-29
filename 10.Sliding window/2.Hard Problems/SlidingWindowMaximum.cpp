#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    vector<int> ans;
    multiset<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
      st.insert(nums[i]);
      if (i >= k)
      {
        st.erase(nums[i - k]);
      }
      if (i >= k - 1)
      {
        ans.push_back(*st.rbegin());
      }
    }
    return ans;
  }
};
// tc:O(n) && sc:O(n)