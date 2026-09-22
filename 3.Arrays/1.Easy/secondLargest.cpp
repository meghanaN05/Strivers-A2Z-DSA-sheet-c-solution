#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int getSecondLargest(vector<int> &arr)
  {
    // code here
    int first = 0;
    int second = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] > first)
      {
        second = first;
        first = arr[i];
      }
      if (arr[i] < first && second < arr[i])
      {
        second = arr[i];
      }
    }
    if (second == 0)
      return -1;
    return second;
  }
};
/*tc:0(n) sc:O(1)*/