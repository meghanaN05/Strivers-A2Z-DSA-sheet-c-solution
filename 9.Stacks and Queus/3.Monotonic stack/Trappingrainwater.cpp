#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // optimized solution(better than stack approach using two pointers)
  int trap(vector<int> &height)
  {
    int left = 0;
    int right = height.size() - 1;
    int leftmax = 0;
    int rightmax = 0;
    int ans = 0;
    while (left <= right)
    {
      if (height[left] <= height[right])
      {
        if (leftmax < height[left])
        {
          leftmax = height[left];
        }
        else
        {
          ans += leftmax - height[left];
        }
        left++;
      }
      else
      {
        if (rightmax < height[right])
        {
          rightmax = height[right];
        }
        else
        {
          ans += rightmax - height[right];
        }
        right--;
      }
    }
    return ans;
  }
};
/*time complexity: O(n), space complexity: O(1)*/