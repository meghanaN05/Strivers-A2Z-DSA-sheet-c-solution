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
  // using reverse logic of the linkedlist
  ListNode *rev(ListNode *head)
  {
    ListNode *prev = NULL;
    ListNode *temp = head;
    while (temp != NULL)
    {
      ListNode *newnode = temp->next;
      temp->next = prev;
      prev = temp;
      temp = newnode;
    }
    return prev;
  }
  bool isPalindrome(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return true;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *secondhalf = rev(slow);
    ListNode *firsthalf = head;
    while (secondhalf)
    {
      if (secondhalf->val != firsthalf->val)
        return false;
      secondhalf = secondhalf->next;
      firsthalf = firsthalf->next;
    }
    return true;
  }
};