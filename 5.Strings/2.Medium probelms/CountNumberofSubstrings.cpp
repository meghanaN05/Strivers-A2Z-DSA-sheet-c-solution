#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int solve(vector<int> &nums, int k)
  {
    int l = 0;
    int maxi = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
      mp[nums[i]]++;
      while (mp.size() > k)
      {
        mp[nums[l]]--;
        if (mp[nums[l]] == 0)
          mp.erase(nums[l]);
        l++;
      }
      maxi += i - l + 1;
    }
    return maxi;
  }
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    return solve(nums, k) - solve(nums, k - 1);
  }
}; // sliding window approach
// CPP program to count number of substrings
// of a string
#include <bits/stdc++.h>
using namespace std;

int countNonEmptySubstr(string str)
{
  int n = str.length();
  return n * (n + 1) / 2;
}

// driver code
int main()
{
  string s = "abcde";
  cout << countNonEmptySubstr(s);
  return 0;
}
// this code is the basic formula to count the number of substrings in a string. The number of non-empty substrings of a string of length n is given by the formula n*(n+1)/2.