#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n; // Input the number of rows for each half (e.g., 5)

  // 1. TOP HALF (Star Pyramid)
  for (int i = 0; i < n; i++)
  {
    // Spaces
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    // Stars (1, 3, 5, 7...)
    for (int k = 0; k < 2 * i + 1; k++)
    {
      cout << "*";
    }
    cout << endl;
  }

  // 2. BOTTOM HALF (Inverted Star Pyramid)
  for (int i = 0; i < n; i++)
  {
    // Spaces (0, 1, 2, 3...)
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }
    // Stars (Shrinking: 2*(n-i)-1)
    for (int k = 0; k < 2 * (n - i) - 1; k++)
    {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}
