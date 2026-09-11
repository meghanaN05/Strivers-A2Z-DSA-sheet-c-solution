#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void solve(int n)
{
  while (n > 0)
  {
    cnt++;
    n /= 10;
  }
}

int main()
{
  int n;
  cin >> n;
  solve(n);
  // using string
  int cnt_string = to_string(n).length();
  cout << cnt << endl;
  return 0;
}
/* time complexity of this code is O(d) where d is the number of digits in the input number n. This is because we are iterating through each digit of the number n and performing a constant time operation for each digit. */