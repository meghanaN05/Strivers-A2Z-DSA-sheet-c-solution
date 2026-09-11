#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<string> ans;
  vector<string> number = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void dfs(int i, string &digits, int n, string curr)
  {
    if (i == n)
    {
      ans.push_back(curr);
      return;
    }
    for (auto &l : number[digits[i] - '0'])
    {
      dfs(i + 1, digits, n, curr + l);
    }
  }
  vector<string> letterCombinations(string digits)
  {
    int n = digits.size();
    dfs(0, digits, n, "");
    return ans;
  }
};
/*time complexity: O(4^n * n) space complexity: O(n)*/