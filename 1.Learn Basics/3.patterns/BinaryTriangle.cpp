#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout << "Enter the value of N: ";
  cin >> n;
  int value = 1;
  for (int i = 0; i < n; i++)
  {

    for (int j = 0; j <= i; j++)
    {
      cout << value << " ";
      value = !value;
    }
    value = i % 2 == 0 ? 0 : 1;
    cout << endl;
  }

  return 0;
}