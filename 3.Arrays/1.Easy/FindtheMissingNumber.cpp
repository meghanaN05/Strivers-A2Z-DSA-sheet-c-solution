#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // using xor;
  int missingNumber(vector<int> &nums)
  {
    int txor = 0;
    int xori = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      txor = txor ^ i;
      xori = xori ^ nums[i];
    }
    txor = txor ^ nums.size();
    return txor ^ xori;
  }
};