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
  ListNode *sortList(ListNode *head)
  {
    // Base case: if list is empty or has only one element
    if (!head || !head->next)
      return head;

    // 1. Split the list into two halves using fast and slow pointers
    ListNode *prev = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    // Disconnect the first half from the second half
    prev->next = nullptr;

    // 2. Recursively sort both halves
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);

    // 3. Merge the two sorted lists
    return merge(l1, l2);
  }

private:
  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        tail->next = l1;
        l1 = l1->next;
      }
      else
      {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
  }
};
// alternative approch using o(1) space
class Solution
{
public:
  ListNode *sortList(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    // Get the length of the list
    int length = 0;
    ListNode *curr = head;
    while (curr)
    {
      length++;
      curr = curr->next;
    }

    ListNode dummy(0);
    dummy.next = head;

    for (int step = 1; step < length; step <<= 1)
    {
      ListNode *prev = &dummy;
      curr = dummy.next;

      while (curr)
      {
        ListNode *left = curr;
        ListNode *right = split(left, step);
        curr = split(right, step);

        prev->next = merge(left, right);
        while (prev->next)
        {
          prev = prev->next;
        }
      }
    }

    return dummy.next;
  }

private:
  // Splits list by step and returns head of second part
  ListNode *split(ListNode *head, int step)
  {
    for (int i = 1; head && i < step; i++)
    {
      head = head->next;
    }
    if (!head)
      return nullptr;
    ListNode *second = head->next;
    head->next = nullptr;
    return second;
  }

  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        tail->next = l1;
        l1 = l1->next;
      }
      else
      {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
  }
};
