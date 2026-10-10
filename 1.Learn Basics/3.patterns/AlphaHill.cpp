#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout << "Enter the value of N: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {

    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    char ch = 'A';
    int k = (2 * i + 1) / 2;
    for (int j = 0; j < 2 * i + 1; j++)
    {
      cout << ch << " ";
      if (j < k)
      {

        ch++;
      }
      else
      {
        ch--;
      }
    }
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    cout << endl;
  }

  return 0;
}