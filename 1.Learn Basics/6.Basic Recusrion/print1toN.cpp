#include <iostream>
using namespace std;
void printNtimes(int i, int n)
{
  if (i == n)
  {
    return;
  }
  cout << i << endl;
  printNtimes(i + 1, n);
}
int main()
{
  int n;
  cin >> n;
  printNtimes(0, n);
  return 0;
}
