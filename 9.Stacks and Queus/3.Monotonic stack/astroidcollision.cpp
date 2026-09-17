#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> asteroidCollision(vector<int> &asteroids)
  {
    stack<int> st;
    for (int x : asteroids)
    {
      bool destroyed = false;
      while (!st.empty() && st.top() > 0 && x < 0)
      {
        if (abs(st.top()) < abs(x))
        {
          st.pop();
          continue;
        }
        else if (abs(st.top()) == abs(x))
          st.pop();
        destroyed = true;
        break;
      }
      if (!destroyed)
      {
        st.push(x);
      }
    }
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
      ans[i] = st.top();
      st.pop();
    }
    return ans;
  }
};
/*time complexity: O(n), space complexity: O(n)*/