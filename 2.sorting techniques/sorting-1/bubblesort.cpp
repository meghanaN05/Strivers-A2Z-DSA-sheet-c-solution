#include <bits/stdc++.h>
using namespace std;
/*
Main Features of Bubble Sort
This is why it is called Bubble Sort: larger elements "bubble up" toward the end.
1. Comparison-based sorting

It sorts elements by comparing them.

2. Adjacent comparison

Only neighboring elements are compared.

arr[j] and arr[j+1]
3. Swapping

If the elements are in the wrong order:

if(arr[j] > arr[j+1])
    swap(arr[j], arr[j+1]);
4. Largest element reaches the end

After every pass:

1st pass → Largest element is fixed.
2nd pass → Second-largest element is fixed.
3rd pass → Third-largest element is fixed.
5. In-place algorithm

It does not require an extra array.

6. Stable sorting algorithm

If two elements have the same value, their relative order remains unchanged.

Example:

5A, 3, 5B

After sorting:

3, 5A, 5B

5A remains before 5B.

7. Adaptive (Optimized Bubble Sort)

With a swapped flag, Bubble Sort can detect whether the array is already sorted
Number of Comparisons

For an array of size n:

Pass 1
n - 1 comparisons
Pass 2
n - 2 comparisons
Pass 3
n - 3 comparisons
Last pass
1 comparison

Therefore:

$$ (n-1)+(n-2)+(n-3)+\dots+1 $$ $$ = \frac{n(n-1)}{2} $$

Therefore:

O(n^2)
  ​
| Case       | Condition      | Time Complexity |
| Best Case  | Array already sorted | O(n)     |
| Average Case | Random order         | O(n²)  |
| Worst Case | Reverse sorted       | O(n²)    |


Best Case Recurrence Relation:T(n)=T(n−1)+O(1)
Worst Case Recurrence Relation:T(n)=T(n−1)+O(n)
Average Case Recurrence Relation:T(n)=T(n−1)+O(n)
*/

void bubble(vector<int> &a)
{
  int n = a.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
      }
    }
  }
}
int32_t main()
{
  int k;
  cin >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++)
    cin >> a[i];
  bubble(a);
  for (int i = 0; i < k; i++)
    cout << a[i] << " ";
  cout << endl;
}