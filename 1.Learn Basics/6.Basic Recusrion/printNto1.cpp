#include <iostream>
using namespace std;
void printNtimes(int n)
{
  if (n <= 0)
  {
    return;
  }
  cout << n << endl;
  printNtimes(n - 1);
}
int main()
{
  int n;
  cin >> n;
  printNtimes(n);
  return 0;
}
// fibonacci series
