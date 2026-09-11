#include <bits/stdc++.h>
using namespace std;

/*
Main Features of Merge Sort

This is why it is called Merge Sort: the array is repeatedly divided into smaller parts, and then the sorted parts are "merged" together to form the final sorted array.

1. Divide and Conquer Algorithm

Merge Sort follows the Divide and Conquer approach.

It works in three main steps:

Divide → Divide the array into two halves.

Conquer → Recursively sort both halves.

Merge → Merge the two sorted halves.

2. Recursive Sorting

Merge Sort recursively divides the array until each subarray contains only one element.

A single element is already sorted.

Base Condition:

if(low >= high)
return;

3. Divides the Array into Two Halves

For every recursive call, the array is divided into two approximately equal halves.

mid = low + (high - low) / 2;

Left Half:

low to mid

Right Half:

mid + 1 to high

4. Single Element is Already Sorted

The array is continuously divided until only one element remains.

Example:

8, 3, 2, 9

↓

8, 3      2, 9

↓

8   3     2   9

Each single element is considered sorted.

5. Merging Sorted Arrays

After dividing, Merge Sort merges two sorted subarrays into one sorted array.

Example:

3, 8

and

2, 9

After merging:

2, 3, 8, 9

6. Comparison-based Sorting

Merge Sort sorts elements by comparing elements from the two sorted halves.

if(arr[left] <= arr[right])

The smaller element is placed into the temporary array first.

7. Stable Sorting Algorithm

Standard Merge Sort is stable.

If two elements have the same value, their relative order remains unchanged.

Example:

5A, 3, 5B

After sorting:

3, 5A, 5B

5A was originally before 5B, and it remains before 5B after sorting.

This is achieved by using:

if(arr[left] <= arr[right])

When both elements are equal, the element from the left subarray is selected first.

8. Not In-place Algorithm

Standard Merge Sort requires an extra temporary array during merging.

Example:

vector<int> temp;

Therefore, it requires additional memory.

9. Not Adaptive

Even if the array is already sorted, Merge Sort still divides the array into smaller subarrays and merges them.

Therefore, its best-case time complexity remains:

O(n log n)

10. Guaranteed Performance

Merge Sort has the same asymptotic time complexity in all cases.

Sorted Array → O(n log n)

Random Array → O(n log n)

Reverse Sorted Array → O(n log n)

Number of Levels

For an array of size n:

n

n/2

n/4

n/8

...

1

The number of levels is:

log₂(n)

Work Done at Each Level

At every level, all n elements are processed during merging.

Therefore:

O(n) work per level

Total number of levels:

O(log n)

Therefore:

O(n) × O(log n)

= O(n log n)

Number of Divisions

The array is repeatedly divided into two halves until single elements are reached.

For n elements, the recursion tree has approximately:

log₂(n) levels

Number of Merges

After dividing the array into single elements, the elements are merged back level by level.

The total merging work across all levels is:

O(n log n)

| Case         | Condition            | Time Complexity |
| ------------ | -------------------- | --------------- |
| Best Case    | Array already sorted | O(n log n)      |
| Average Case | Random order         | O(n log n)      |
| Worst Case   | Reverse/random order | O(n log n)      |

Best Case Recurrence Relation:

T(n) = 2T(n/2) + O(n)

Even if the array is already sorted, Merge Sort still divides the array into two halves and merges them.

Therefore:

T(n) = O(n log n)

Worst Case Recurrence Relation:

T(n) = 2T(n/2) + O(n)

Merge Sort divides the array into two halves and processes all n elements while merging.

Therefore:

T(n) = O(n log n)

Average Case Recurrence Relation:

T(n) = 2T(n/2) + O(n)

For a randomly arranged array, Merge Sort still divides the array and merges all elements.

Therefore:

T(n) = O(n log n)

Space Complexity:

Merge Sort requires an additional temporary array for merging.

It uses:

temp array → O(n)

Recursion stack → O(log n)

The dominant space complexity is:

O(n)

Therefore:

O(n)

Important Properties:

| Property                | Merge Sort |
| ----------------------- | ---------- |
| Comparison-based        | Yes        |
| Divide and Conquer      | Yes        |
| Recursive               | Yes        |
| In-place                | No         |
| Stable                  | Yes        |
| Adaptive                | No         |
| Best Time Complexity    | O(n log n) |
| Average Time Complexity | O(n log n) |
| Worst Time Complexity   | O(n log n) |
| Space Complexity        | O(n)       |
| Number of Levels        | log₂(n)    |
| Work per Level          | O(n)       |
| Good for Linked Lists   | Yes        |
| Good for Large Data     | Yes        |
| Guaranteed Performance  | O(n log n) |

When Merge Sort is Used

1. Large Data Sets

Merge Sort is efficient for large data sets because its worst-case time complexity is:

O(n log n)

2. Linked Lists

Merge Sort is particularly efficient for linked lists because merging can be done by changing pointers.

3. External Sorting

Merge Sort is useful when the complete data cannot fit into memory.

It is used for:

Large files

Databases

External memory sorting

4. Stable Sorting Required

Merge Sort is useful when the relative order of equal elements must be maintained.

5. Guaranteed O(n log n) Performance

It is useful when predictable worst-case performance is required.

**Recurrence Relations Summary**

Best Case Recurrence Relation:

T(n) = 2T(n/2) + O(n)

Worst Case Recurrence Relation:

T(n) = 2T(n/2) + O(n)

Average Case Recurrence Relation:

T(n) = 2T(n/2) + O(n)


*/
void merge(int l, int mid, int r, vector<int> &a)
{
  int left = l;
  int right = mid + 1;
  vector<int> temp;
  while (left <= mid && right <= r)
  {
    if (a[left] <= a[right])
    {
      temp.push_back(a[left]);
      left++;
    }
    else
    {
      temp.push_back(a[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(a[left]);
    left++;
  }
  while (right <= r)
  {
    temp.push_back(a[right]);
    right++;
  }
  for (int i = l; i <= r; i++)
  {
    a[i] = temp[i - l];
  }
}

void mergesort(int l, int r, vector<int> &a)
{
  if (l >= r)
    return;
  int mid = l + (r - l) / 2;
  mergesort(l, mid, a);
  mergesort(mid + 1, r, a);
  merge(l, mid, r, a);
}
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  mergesort(0, n - 1, a);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}