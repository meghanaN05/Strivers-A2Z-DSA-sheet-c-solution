#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout << "Enter the value of N: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    char ch = 'A' + i;
    for (int j = 0; j <= n - i - 1; j++)
    {
      cout << ch;
      ch++;
    }
    cout << endl;
  }

  return 0;
}