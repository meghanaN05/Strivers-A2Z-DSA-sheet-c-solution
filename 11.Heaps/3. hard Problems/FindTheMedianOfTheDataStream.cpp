#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
  priority_queue<int, vector<int>, greater<int>> minHeap;
  priority_queue<int> maxHeap;
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    maxHeap.push(num);
    if (!minHeap.empty() && maxHeap.top() > minHeap.top())
    {
      int x = maxHeap.top();
      maxHeap.pop();
      minHeap.push(x);
    }
    if (maxHeap.size() > minHeap.size() + 1)
    {
      int x = maxHeap.top();
      maxHeap.pop();
      minHeap.push(x);
    }
    else if (minHeap.size() > maxHeap.size())
    {
      int x = minHeap.top();
      minHeap.pop();
      maxHeap.push(x);
    }
  }

  double findMedian()
  {
    if (maxHeap.size() > minHeap.size())
      return maxHeap.top();
    return (maxHeap.top() + minHeap.top()) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class Solution
{
public:
  vector<double> getMedian(vector<int> &arr)
  {
    vector<double> ans;
    priority_queue<double> maxheap;
    priority_queue<double, vector<double>, greater<double>> minheap;
    for (int i = 0; i < arr.size(); i++)
    {
      maxheap.push(arr[i]);
      if (!minheap.empty() && maxheap.top() > minheap.top())
      {
        double x = maxheap.top();
        maxheap.pop();
        minheap.push(x);
      }
      if (maxheap.size() > minheap.size() + 1)
      {
        double x = maxheap.top();
        maxheap.pop();
        minheap.push(x);
      }
      else if (minheap.size() > maxheap.size())
      {
        double x = minheap.top();
        minheap.pop();
        maxheap.push(x);
      }
      if (maxheap.size() == minheap.size())
      {
        ans.push_back((maxheap.top() + minheap.top()) / 2.0);
      }
      else
      {
        ans.push_back(maxheap.top());
      }
    }
    return ans;
  }
};