#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
  ListNode *ReverseList(ListNode *head)
  {
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
      ListNode *dummy = temp->next;
      temp->next = prev;
      prev = temp;
      temp = dummy;
    }
    return prev;
  }
};