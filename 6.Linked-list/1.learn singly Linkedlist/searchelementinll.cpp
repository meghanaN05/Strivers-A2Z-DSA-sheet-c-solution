#include <bits/stdc++.h>
using namespace std;
/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution
{
public:
  bool searchKey(Node *head, int key)
  {
    // Code here
    Node *temp = head;
    while (temp != NULL)
    {
      if (temp->data == key)
        return true;
      temp = temp->next;
    }
    return false;
  }
};
/*tc:O(n) && sc:O(1)*/