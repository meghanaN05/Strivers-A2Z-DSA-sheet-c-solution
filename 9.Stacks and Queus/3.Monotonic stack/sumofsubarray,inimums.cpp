#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int sumSubarrayMins(vector<int> &arr)
  {
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n);
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && arr[st.top()] >= arr[i])
        st.pop();
      nse[i] = st.empty() ? n : st.top();
      st.push(i);
    }
    vector<int> pse(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
      while (!s.empty() && arr[s.top()] > arr[i])
        s.pop();
      pse[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }
    int mod = 1e9 + 7;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      long long left = i - pse[i];
      long long right = nse[i] - i;
      sum += ((left * right % mod) * arr[i]) % mod;
      sum %= mod;
    }
    return (int)sum;
  }
};
/*time complexity: O(n), space complexity: O(n)*/