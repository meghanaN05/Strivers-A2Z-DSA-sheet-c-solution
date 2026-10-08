#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout << "Enter the value of N: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x = 1;
    int spaces = 2 * (n - i - 1);
    for (int j = 0; j <= i; j++)
    {
      cout << x;
      x++;
    }
    for (int k = 0; k < spaces; k++)
    {
      cout << " ";
    }
    x--;
    for (int j = 0; j <= i; j++)
    {
      cout << x;
      x--;
    }
    cout << endl;
  }

  return 0;
}