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
  ListNode *middleNode(ListNode *head)
  {
    if (head == NULL)
      return NULL;
    ListNode *temp1 = head;
    ListNode *temp2 = head;
    while (temp2 && temp2->next)
    {
      temp1 = temp1->next;
      temp2 = temp2->next->next;
    }
    return temp1;
  }
};