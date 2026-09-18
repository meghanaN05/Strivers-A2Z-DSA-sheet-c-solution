#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int pageFaults(vector<int> &pages, int c)
  {
    int N = pages.size();
    vector<int> memory;
    int faults = 0;
    for (int i = 0; i < N; i++)
    {
      int page = pages[i];
      auto it = find(memory.begin(), memory.end(), page);
      if (it == memory.end())
      {
        faults++;
        if (memory.size() == c)
        {
          memory.erase(memory.begin());
        }
      }
      else
      {
        memory.erase(it);
      }
      memory.push_back(page);
    }

    return faults;
  }
};
/*TC = O(n)
SC = O(n)*/