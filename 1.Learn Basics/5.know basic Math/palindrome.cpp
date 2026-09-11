#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin > n;
  int rev = 0;
  int num = n;
  while (n > 0)
  {
    int digit = n % 10;
    rev = rev * 10 + digit;
    n /= 10;
  }
  if (num == rev)
  {
    cout << "Palindrome" << endl;
  }
  else
  {
    cout << "Not Palindrome" << endl;
  }
}
/* time complexity of this code is O(d) where d is the number of digits in the input number n. This is because we are iterating through each digit of the number n and performing a constant time operation for each digit. */