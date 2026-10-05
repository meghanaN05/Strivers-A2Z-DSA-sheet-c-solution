#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isPalindrome(string s)
  {
    string filtered;
    for (char c : s)
    {
      if (isalnum(c))
      {
        filtered += tolower(c);
      }
    }
    int left = 0, right = filtered.size() - 1;
    while (left < right)
    {
      if (filtered[left] != filtered[right])
      {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};
// check if the string is palindrome or not using recursion
bool isPalindromeRecursive(const string &s, int left, int right)
{
  if (left >= right)
  {
    return true;
  }
  if (s[left] != s[right])
  {
    return false;
  }
  return isPalindromeRecursive(s, left + 1, right - 1);
}