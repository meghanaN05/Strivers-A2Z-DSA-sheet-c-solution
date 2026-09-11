#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int m;
  cin >> m;
  // using inbuilt function
  int gdc = __gcd(n, m);
  cout << gdc << endl;
  // using mathematical formula
  int gcd_formula = 1;
  for (int i = 1; i <= min(n, m); i++)
  {
    if (n % i == 0 && m % i == 0)
    {
      gcd_formula = i;
    }
  }
  /* time complexity of this code is O(min(n, m)) because we are iterating through all numbers from 1 to the smaller of the two input numbers n and m. */
  // using recursive function
  int gcd_recursive(int a, int b)
  {
    if (b == 0)
    {
      return a;
    }
    return gcd_recursive(b, a % b);
  }
  cout << gcd_recursive(n, m) << endl;
}
/* time complexity of this code is O(log(min(n, m))) because we are using the Euclidean algorithm, which reduces the problem size by a factor of at least 2 in each recursive call. */