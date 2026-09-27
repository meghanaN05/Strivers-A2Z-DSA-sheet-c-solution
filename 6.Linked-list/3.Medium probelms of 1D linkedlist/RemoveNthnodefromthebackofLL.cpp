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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    int size = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
      size++;
      temp = temp->next;
    }
    int N = size - n + 1;
    if (head == NULL)
      return head;
    if (N == 1)
    {
      ListNode *dummy = head;
      head = head->next;
      delete dummy;
      return head;
    }
    int cnt = 1;
    temp = head;
    while (cnt < N - 1)
    {
      temp = temp->next;
      cnt++;
    }
    ListNode *dummy = temp->next;
    temp->next = temp->next->next;
    delete dummy;
    return head;
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *dummy = new ListNode(0, head);
    ListNode *fast = dummy;
    ListNode *slow = dummy;
    for (int i = 0; i < n; i++)
    {
      fast = fast->next;
    }
    while (fast->next != NULL)
    {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    ListNode *newhead = dummy->next;
    delete dummy;
    return newhead;
  }
};