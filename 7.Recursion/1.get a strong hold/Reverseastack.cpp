#include <bits/stdc++.h>
using namespace std;
// User function Template for C++
class Solution
{
public:
  void insertAtBottom(stack<int> &St, int x)
  {
    if (St.empty())
    {
      St.push(x);
      return;
    }
    int temp = St.top();
    St.pop();
    insertAtBottom(St, x);
    St.push(temp);
  }

  void Reverse(stack<int> &St)
  {
    if (St.empty())
      return;

    int temp = St.top();
    St.pop();

    Reverse(St);

    insertAtBottom(St, temp);
  }
};
/*time complexity: O(n^2), space complexity: O(n)*/