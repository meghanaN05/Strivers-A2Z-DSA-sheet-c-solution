#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> findUnion(vector<int> &a, vector<int> &b)
  {
    // code here
    set<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
      ans.insert(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
      ans.insert(b[i]);
    }
    vector<int> res(ans.begin(), ans.end());
    return res;
  }
};
/*tc:0(n) sc:O(n)*/
