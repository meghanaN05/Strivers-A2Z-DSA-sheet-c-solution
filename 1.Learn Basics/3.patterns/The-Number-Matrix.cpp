/*
The Number Matrix Pattern
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout << "Enter the value of N: ";
  cin >> n;
  int size = 2 * n - 1;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      int top = i;
      int left = j;
      int bottom = (size - 1) - i;
      int right = (size - 1) - j;
      int value = n - min({top, left, bottom, right});
      cout << value << " ";
    }
    cout << endl;
  }
  return 0;
}
