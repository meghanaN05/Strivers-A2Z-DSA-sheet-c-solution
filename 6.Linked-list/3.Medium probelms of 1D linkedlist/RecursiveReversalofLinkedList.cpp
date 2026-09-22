#include <bits/stdc++.h>
using namespace std;
ListNode *ReverseList(ListNode *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  ListNode *newHead = ReverseList(head->next);

  head->next->next = head;
  head->next = nullptr;

  return newHead;
}