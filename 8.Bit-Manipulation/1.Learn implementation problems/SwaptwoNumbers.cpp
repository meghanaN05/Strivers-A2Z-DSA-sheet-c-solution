#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a = 10;
  int b = 20;

  cout << "Before swap: a = " << a << ", b = " << b << endl;

  // XOR swap algorithm
  a = a ^ b; // Step 1: 'a' now holds the combined bits of both numbers
  b = a ^ b; // Step 2: 'b' becomes the original value of 'a'
  a = a ^ b; // Step 3: 'a' becomes the original value of 'b'

  cout << "After swap: a = " << a << ", b = " << b << endl;

  return 0;
}
