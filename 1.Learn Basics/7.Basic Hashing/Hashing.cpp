// give me the code for hashing in c++ with comments and explaination
/*Below is a simple implementation of hashing in C++ using a hash table. This example demonstrates how to use a hash table to store and retrieve key-value pairs. The implementation uses the C++ Standard Library's `unordered_map`, which provides an efficient way to handle hashing.
```cpp
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
  // Create a hash table to store key-value pairs
  unordered_map<string, int> hashTable;

  // Insert key-value pairs
  hashTable["apple"] = 5;
  hashTable["banana"] = 10;
  hashTable["orange"] = 15;

  // Retrieve values using keys
  cout << "Apple: " << hashTable["apple"] << endl;
  cout << "Banana: " << hashTable["banana"] << endl;
  cout << "Orange: " << hashTable["orange"] << endl;

  return 0;
}