#include <bits/stdc++.h>
using namespace std;
class minHeap
{
public:
  priority_queue<int, vector<int>, greater<int>> pq;

  void push(int x)
  {
    pq.push(x);
  }

  void pop()
  {
    if (!pq.empty())
      pq.pop();
  }

  int peek()
  {
    if (pq.empty())
      return -1;

    return pq.top();
  }

  int size()
  {
    return pq.size();
  }
};