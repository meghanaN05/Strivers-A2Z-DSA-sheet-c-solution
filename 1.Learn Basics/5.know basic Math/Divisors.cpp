#include <bits/stdc++.h>
using namespace std;
int divisor_cnt(int n)
{
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      cnt++;
    }
  }
  return cnt;
}
void divisor(int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      cout << i << " ";
    }
  }
}
int main()
{
  int n;
  cin >> n;
  int ans = divisor_cnt(n);
  divisor(n);
  cout << ans << endl;
}
/* time complexity of this code is O(n) because we are checking for factors of n by iterating through all numbers from 1 to n. This is efficient for finding the number of divisors and the divisors themselves for small values of n. For larger values of n, more efficient algorithms can be used to find the number of divisors and the divisors themselves in O(sqrt(n)) time complexity. */
