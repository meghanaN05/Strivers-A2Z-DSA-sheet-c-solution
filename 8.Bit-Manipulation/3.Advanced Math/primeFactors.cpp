#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // brute force approach-finding all the unique prime factors
  int distinctPrimeFactors(vector<int> &nums)
  {
    int n = 1;
    for (int i = 0; i < nums.size(); i++)
      n *= nums[i];
    set<int> ans;
    while (n % 2 == 0)
    {
      ans.insert(2);
      n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
      while (n % i == 0)
      {
        ans.insert(i);
        n /= i;
      }
    }
    if (n > 2)
    {
      ans.insert(n);
    }
    return ans.size();
  }
};
class Solution
{
public:
  // optimized solution-finding all the unique prime factors
  int distinctPrimeFactors(vector<int> &nums)
  {
    set<int> ans;
    for (int num : nums)
    {
      int n = num;
      while (n % 2 == 0)
      {
        ans.insert(2);
        n = n / 2;
      }
      for (int i = 3; i * i <= n; i += 2)
      {
        while (n % i == 0)
        {
          ans.insert(i);
          n = n / i;
        }
      }
      if (n > 2)
      {
        ans.insert(n);
      }
    }
    return ans.size();
  }
};