#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> leaders(vector<int> &arr)
  {
    // code here
    vector<int> v;
    int n = arr.size();

    int current_max = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
      if (arr[i] >= current_max)
      {
        current_max = arr[i];
        v.push_back(current_max);
      }
    }

    reverse(v.begin(), v.end());

    return v;
  }
};