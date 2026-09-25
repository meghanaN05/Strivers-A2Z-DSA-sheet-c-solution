#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> findSubarray(vector<int> &arr)
  {
    long long max_sum = -1;
    long long current_sum = 0;
    int start = 0, current_start = 0;
    int max_len = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] >= 0)
      {
        current_sum += arr[i];
        int current_len = i - current_start + 1;
        if (current_sum > max_sum || (current_sum == max_sum && current_len > max_len))
        {
          max_sum = current_sum;
          max_len = current_len;
          start = current_start;
        }
      }
      else
      {
        // Reset tracker for the next non-negative segment
        current_sum = 0;
        current_start = i + 1;
      }
    }

    // If no non-negative segment was found
    if (max_sum == -1)
    {
      return {-1};
    }

    return vector<int>(arr.begin() + start, arr.begin() + start + max_len);
  }
};