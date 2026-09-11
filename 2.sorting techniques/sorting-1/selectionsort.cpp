#include <bits/stdc++.h>
using namespace std;
/*


Main Features of Selection Sort

This is why it is called Selection Sort: in every pass, the smallest element from the unsorted part is "selected" and placed at its correct position at the beginning.

1. Comparison-based sorting

It sorts elements by comparing them.

2. Finds Minimum Element

In every pass, Selection Sort finds the smallest element from the unsorted part of the array.

3. Minimum Index Tracking

It keeps track of the index of the smallest element.

minIndex = i

if(arr[j] < arr[minIndex])
minIndex = j;

4. Smallest Element Reaches the Beginning

After every pass:

1st pass → Smallest element is fixed.
2nd pass → Second-smallest element is fixed.
3rd pass → Third-smallest element is fixed.

5. Swapping

After finding the smallest element, it is swapped with the first element of the unsorted portion.

swap(arr[i], arr[minIndex]);

6. In-place Algorithm

It does not require an extra array.

It only uses a few extra variables.

7. Not Stable Sorting Algorithm

Standard Selection Sort is not stable.

If two elements have the same value, their relative order may change after swapping.

Example:

5A, 3, 5B, 2

After sorting:

2, 3, 5B, 5A

5A was originally before 5B, but after sorting their relative order changes.

8. Not Adaptive

Even if the array is already sorted, Selection Sort still compares all the remaining elements to find the minimum element.

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

\((n-1)+(n-2)+(n-3)+\dots+1\)

\(=\frac{n(n-1)}{2}\)

Therefore:

\(O(n^2)\)

Number of Swaps

Selection Sort performs at most one swap per pass.

Therefore:

Maximum number of swaps:

\(n-1\)

Therefore:

\(O(n)\)

| Case         | Condition            | Time Complexity |
| ------------ | -------------------- | --------------- |
| Best Case    | Array already sorted | O(n²)           |
| Average Case | Random order         | O(n²)           |
| Worst Case   | Reverse sorted       | O(n²)           |

Best Case Recurrence Relation:

T(n)=T(n−1)+O(n)

Even if the array is already sorted, Selection Sort still scans the remaining unsorted elements to find the minimum.

Therefore:

\(T(n)=O(n^2)\)

Worst Case Recurrence Relation:

T(n)=T(n−1)+O(n)

In every pass, the algorithm scans the entire unsorted portion to find the minimum element.

Therefore:

\(T(n)=O(n^2)\)

Average Case Recurrence Relation:

T(n)=T(n−1)+O(n)

For a randomly arranged array, Selection Sort still scans the entire unsorted portion to find the minimum element.

Therefore:

\(T(n)=O(n^2)\)

Space Complexity:

Selection Sort does not require any extra array.

It only uses variables such as:

i, j, minIndex

Therefore:

\(O(1)\)

Important Properties:

| Property                | Selection Sort |
| ----------------------- | -------------- |
| Comparison-based        | Yes            |
| In-place                | Yes            |
| Stable                  | No             |
| Adaptive                | No             |
| Best Time Complexity    | O(n²)          |
| Average Time Complexity | O(n²)          |
| Worst Time Complexity   | O(n²)          |
| Space Complexity        | O(1)           |
| Maximum Comparisons     | n(n−1)/2       |
| Maximum Swaps           | n−1            |

**Recurrence Relations Summary**

Best Case Recurrence Relation:

T(n)=T(n−1)+O(n)

Worst Case Recurrence Relation:

T(n)=T(n−1)+O(n)

Average Case Recurrence Relation:

T(n)=T(n−1)+O(n)
*/
void selectionsort(vector<int> &a)
{
  int n = a.size();
  for (int i = 0; i < n - 1; i++)
  {
    int mini = i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[mini])
      {
        mini = j;
      }
    }
    swap(a[i], a[mini]);
  }
}
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  selectionsort(a);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}