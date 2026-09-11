#include <bitset>/stdc++.h>
using namespace std;
class Solution
{
public:
  void insert(stack<int> &st, int x)
  {
    if (st.empty() || st.top() <= x)
    {
      st.push(x);
      return;
    }
    else
    {
      int temp = st.top();
      st.pop();
      insert(st, x);
      st.push(temp);
    }
  }
  void sortStack(stack<int> &st)
  {
    // code here
    if (st.empty())
      return;
    int x = st.top();
    st.pop();
    sortStack(st);
    insert(st, x);
  }
};
/*time complexity: O(n^2), space complexity: O(n)*/
