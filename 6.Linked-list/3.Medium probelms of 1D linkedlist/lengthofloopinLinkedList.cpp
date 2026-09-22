#include <bits/stdc++.h>
using namespace std;
/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution
{
public:
  int lengthOfLoop(Node *head)
  {
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        int count = 1;
        fast = fast->next;
        while (fast != slow)
        {
          count++;
          fast = fast->next;
        }
        return count;
      }
    }
    return 0;
  }
};