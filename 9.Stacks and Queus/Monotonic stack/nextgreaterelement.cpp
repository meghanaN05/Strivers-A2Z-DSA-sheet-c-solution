#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    stack<int> st;
    unordered_map<int, int> mp;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() < nums2[i])
        st.pop();
      if (st.size())
      {
        mp[nums2[i]] = st.top();
      }
      else
      {
        mp[nums2[i]] = -1;
      }
      st.push(nums2[i]);
    }
    vector<int> ans(nums1.size());
    for (int i = 0; i < nums1.size(); i++)
    {
      ans[i] = mp[nums1[i]];
    }
    return ans;
  }
};
/*time complexity: O(n+m), where n is the size of nums1 and m is the size of nums2*/
/*space complexity: O(m), where m is the size of nums2*/