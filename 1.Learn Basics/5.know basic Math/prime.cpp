#include <bits/stdc++.h>
using namespace std;
/*time complexity of this code is O(sqrt(n)) because we are checking for factors only up to the square root of n. This is efficient for checking if a number is prime.*/
int main()
{
  int n;
  cin >> n;
  bool isPrime = true;
  if (n <= 1)
  {
    isPrime = false;
  }
  else
  {
    for (int i = 2; i * i <= n; i++)
    {
      if (n % i == 0)
      {
        isPrime = false;
        break;
      }
    }
  }
  if (isPrime)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
// using sieve of Eratosthenes to find all prime numbers up to n
void sieve(int n)
{
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= n; i++)
  {
    if (isPrime[i])
    {
      for (int j = i * i; j <= n; j += i)
      {
        isPrime[j] = false;
      }
    }
  }
  for (int i = 2; i <= n; i++)
  {
    if (isPrime[i])
    {
      cout << i << " ";
    }
  }
}
// time complexity of this code is O(n log log n) because we are using the sieve of Eratosthenes algorithm to find all prime numbers up to n. This is efficient for finding all prime numbers in a range.
