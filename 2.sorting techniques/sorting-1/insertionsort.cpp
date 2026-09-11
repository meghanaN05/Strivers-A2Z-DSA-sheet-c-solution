#include <bits/stdc++.h>
using namespace std;
/* */
void insertionsort(vector<int> &a)
{
  int n = a.size();
  for (int i = 1; i < n; i++)
  {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  insertionsort(a);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}