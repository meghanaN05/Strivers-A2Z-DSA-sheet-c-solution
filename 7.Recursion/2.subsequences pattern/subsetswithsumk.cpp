#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool backtrack(int i, vector<int> &arr, int k, int n)
  {
    if (k == 0)
      return true;
    if (i == n)
      return false;
    return backtrack(i + 1, arr, k - arr[i], n) || backtrack(i + 1, arr, k, n);
  }
  bool checkSubsequenceSum(int n, vector<int> &arr, int k)
  {
    return backtrack(0, arr, k, n);
  }
};
/*time complexity: O(2^n) space complexity: O(n)*/