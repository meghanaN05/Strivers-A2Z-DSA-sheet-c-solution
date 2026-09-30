/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  Node *segregate(Node *head)
  {
    if (!head || !head->next)
      return head;

    // Dummy heads and tails for 0, 1, 2 lists
    Node *zeroHead = new Node(-1), *oneHead = new Node(-1), *twoHead = new Node(-1);
    Node *zero = zeroHead, *one = oneHead, *two = twoHead;

    // Distribute nodes into lists
    Node *curr = head;
    while (curr)
    {
      if (curr->data == 0)
      {
        zero->next = curr;
        zero = zero->next;
      }
      else if (curr->data == 1)
      {
        one->next = curr;
        one = one->next;
      }
      else
      {
        two->next = curr;
        two = two->next;
      }
      curr = curr->next;
    }

    // Connect lists: 0 → 1 → 2
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    // New head
    head = zeroHead->next;

    // Cleanup dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
  }
};