#include <bits/stdc++.h>
using namespace std;
void minheapify(vector<int> &arr, int i)
{
  int n = arr.size();
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && arr[l] < arr[i])
    smallest = l;
  if (r < n && arr[r] < arr[smallest])
    smallest = r;
  if (i != smallest)
  {
    swap(arr[i], arr[smallest]);
    minheapify(arr, smallest);
  }
}
vector<int> MinToMaxHeap(int n, vector<int> &arr)
{

  for (int i = (n - 2) / 2; i >= 0; i--)
  {
    minheapify(arr, i);
  }
  return arr;
}