#include <bits/stdc++.h>
using namespace std;
int findHighestAndLowest(vector<int> &arr, map<int, int> &mp)
{
  int highest = INT_MIN;
  int lowest = INT_MAX;
  for (auto it : mp)
  {
    highest = max(highest, it.second);
    lowest = min(lowest, it.second);
  }
  cout << "Highest: " << highest << endl;
  cout << "Lowest: " << lowest << endl;
}
