#include <iostream>
using namespace std;
void printNameNtimes(int n)
{
  if (n <= 0)
  {
    return;
  }
  cout << "Meghana N" << endl;
  printNameNtimes(n - 1);
}
int main()
{
  int n;
  cin >> n;
  printNameNtimes(n);
  return 0;
}
// fibonacci series
