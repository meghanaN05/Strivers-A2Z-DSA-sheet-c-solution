#include <bits/stdc++.h>
using namespace std;
/*
This is a C++ program that prints a symmetric pattern of asterisks and spaces based
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/
int main()
{
  int n;
  cout << "Enter the value of N: ";
  cin >> n;
  int space = 0;
  for (int i = 0; i < n; i++)
  {
    // Left stars
    for (int j = 1; j <= n - i; j++)
      cout << "*";
    // Void spaces
    for (int j = 1; j <= space; j++)
      cout << " ";
    // Right stars
    for (int j = 1; j <= n - i; j++)
      cout << "*";

    cout << endl;
    space += 2;
  }

  // 2. Lower Half
  space = 2 * n - 2;
  for (int i = 0; i < n; i++)
  {
    // Left stars
    for (int j = 1; j <= i + 1; j++)
      cout << "*";
    // Void spaces
    for (int j = 1; j <= space; j++)
      cout << " ";
    // Right stars
    for (int j = 1; j <= i + 1; j++)
      cout << "*";

    cout << endl;
    space -= 2;
  }
  return 0;
}
