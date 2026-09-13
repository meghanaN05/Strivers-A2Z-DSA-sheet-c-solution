#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // optimal approach
  string countAndSay(int n)
  {
    string res = "1";
    for (int i = 1; i < n; i++)
    {
      string temp;
      temp.reserve(res.size() * 2);
      int cnt = 1;
      for (int j = 1; j < res.size(); j++)
      {
        if (res[j] == res[j - 1])
        {
          cnt++;
        }
        else
        {
          temp += to_string(cnt);
          temp += res[j - 1];
          cnt = 1;
        }
      }
      temp += to_string(cnt);
      temp += res.back();
      res = temp;
    }
    return res;
  }
};
/*time complexity: O(n^2), space complexity: O(n) where n is the input number*/