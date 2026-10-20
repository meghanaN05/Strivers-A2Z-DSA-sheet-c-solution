#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // using map
  vector<int> arrayRankTransform(vector<int> &arr)
  {
    vector<int> originalArray = arr;
    sort(arr.begin(), arr.end());
    map<int, int> mp;
    int rank = 1;
    for (int i = 0; i < arr.size(); i++)
    {
      if (mp.find(arr[i]) == mp.end())
      {
        mp[arr[i]] = rank++;
      }
    }
    for (int i = 0; i < arr.size(); i++)
    {
      arr[i] = mp[originalArray[i]];
    }

    return arr;
  }
};
// using priority queue
// User function Template for C++

class Solution
{
public:
  vector<int> replaceWithRank(vector<int> &arr, int N)
  {
    int n = arr.size();
    vector<int> res(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < n; i++)
    {
      pq.push({arr[i], i});
    }
    int rank = 0;
    int lastNum = INT_MAX;
    while (!pq.empty())
    {
      int curr = pq.top().first;
      int index = pq.top().second;
      pq.pop();
      if (lastNum == INT_MAX || curr != lastNum)
      {
        rank++;
      }
      res[index] = rank;
      lastNum = curr;
    }
    return res;
  }
};