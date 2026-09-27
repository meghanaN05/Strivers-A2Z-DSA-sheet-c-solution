#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    ListNode oddDummy(0), evenDummy(0);
    ListNode *odd = &oddDummy;
    ListNode *even = &evenDummy;
    int i = 1;
    while (head)
    {
      if (i % 2 == 1)
      {
        odd->next = new ListNode(head->val);
        odd = odd->next;
      }
      else
      {
        even->next = new ListNode(head->val);
        even = even->next;
      }
      head = head->next;
      i++;
    }
    odd->next = evenDummy.next;
    return oddDummy.next;
  }
};
// alternative approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenhead = even;
    while (even && even->next)
    {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    odd->next = evenhead;
    return head;
  }
};