#include <bits/stdc++.h>
using namespace std;
/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution
{
public:
  Node *insertPos(Node *head, int pos, int val)
  {
    // code here
    Node *temp = new Node(val);
    if (pos == 1)
    {
      temp->next = head;
      return temp;
    }
    Node *curr = head;
    int cnt = 1;
    while (cnt < pos - 1 && curr != NULL)
    {
      curr = curr->next;
      cnt++;
    }

    if (curr != NULL)
    {
      temp->next = curr->next;
      curr->next = temp;
    }
    return head;
  }
};
/*tc:O(n) && sc:O(1)*/