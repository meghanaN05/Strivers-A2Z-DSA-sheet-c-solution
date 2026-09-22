#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// using space for map
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    unordered_map<ListNode *, int> mp;
    ListNode *temp = head;
    while (temp != NULL)
    {
      if (mp.find(temp) == mp.end())
      {
        mp[temp]++;
      }
      else
      {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }
};
// using without extra spacez;
bool hasCycle(ListNode *head)
{
  if (!head || !head->next)
    return false;
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true; // cycle detected
  }
  return false;
}