#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    unordered_map<char, int> countMap;
    for (char task : tasks)
    {
      countMap[task]++;
    }
    priority_queue<int> maxHeap;
    for (auto &pair : countMap)
    {
      maxHeap.push(pair.second);
    }
    queue<pair<int, int>> cooldownQueue;
    int time = 0;
    while (!maxHeap.empty() || !cooldownQueue.empty())
    {
      time++;
      if (!cooldownQueue.empty() && cooldownQueue.front().second == time)
      {
        maxHeap.push(cooldownQueue.front().first);
        cooldownQueue.pop();
      }
      if (!maxHeap.empty())
      {
        int freq = maxHeap.top();
        maxHeap.pop();
        if (freq - 1 > 0)
        {
          cooldownQueue.push({freq - 1, time + n + 1});
        }
      }
    }

    return time;
  }
};