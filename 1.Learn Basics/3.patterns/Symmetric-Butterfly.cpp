/*

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout << "Enter the value of N: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << "*";
    }
    int space = 2 * n - (2 * i);
    for (int k = 0; k < space; k++)
    {
      cout << " ";
    }
    for (int j = 0; j < i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 0; i < 2 * n; i++)
  {
    cout << "*";
  }
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << "*";
    }
    int space = 2 * i + 2;
    for (int k = 0; k < space; k++)
    {
      cout << " ";
    }
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
