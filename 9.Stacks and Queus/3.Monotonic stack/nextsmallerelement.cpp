#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> nextSmallerEle(vector<int> &arr)
  {
    int n = arr.size();
    stack<int> st;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() >= arr[i])
      {
        st.pop();
      }
      if (st.empty())
        res[i] = -1;
      else
        res[i] = st.top();
      st.push(arr[i]);
    }
    return res;
  }
};
/*time complexity: O(n), where n is the size of arr*/
/*space complexity: O(n), where n is the size of arr*/