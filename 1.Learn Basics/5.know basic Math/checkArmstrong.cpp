#include <bits/stdc++.h>
using namespace std;
int digits(int n)
{
  int cnt = 0;
  while (n > 0)
  {
    cnt++;
    n = n / 10;
  }
  return cnt;
}
int main()
{
  int n;
  cin >> n;
  int digitcount = digits(n);
  int sum = 0;
  while (n > 0)
  {
    int rem = n % 10;
    sum += pow(rem, digitcount);
    n = n / 10;
  }
  if (sum == n)
  {
    cout << "Armstrong Numner" << endl;
  }
  else
  {
    cout << "Not an Armstrong Number" << endl;
  }
}
/* time complexity of this code is O(d) where d is the number of digits in the input number n. This is because we are iterating through each digit of the number n and performing a constant time operation for each digit. */