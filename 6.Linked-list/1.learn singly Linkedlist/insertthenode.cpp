#include <bits/stdc++.h>
using namespace std;
class MyLinkedList
{
public:
  struct ListNode
  {
    int val;
    ListNode *next;
    ListNode(int x)
    {
      val = x;
      next = NULL;
    }
  };
  ListNode *head;
  int cnt;
  MyLinkedList()
  {
    head = NULL;
    cnt = 0;
  }
  int get(int index)
  {
    if (index < 0 || index >= cnt)
      return -1;
    ListNode *temp = head;
    while (index--)
    {
      temp = temp->next;
    }
    return temp->val;
  }

  void addAtHead(int val)
  {
    ListNode *newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
    cnt++;
  }

  void addAtTail(int val)
  {
    ListNode *newNode = new ListNode(val);

    if (head == NULL)
    {
      head = newNode;
      cnt++;
      return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    cnt++;
  }

  void addAtIndex(int index, int val)
  {
    if (index < 0 || index > cnt)
      return;
    if (index == 0)
    {
      addAtHead(val);
      return;
    }
    if (index == cnt)
    {
      addAtTail(val);
      return;
    }
    ListNode *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
      temp = temp->next;
    }
    ListNode *newNode = new ListNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    cnt++;
  }

  void deleteAtIndex(int index)
  {
    if (index < 0 || index >= cnt)
      return;
    if (index == 0)
    {
      ListNode *del = head;
      head = head->next;
      delete del;
      cnt--;
      return;
    }

    ListNode *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
      temp = temp->next;
    }
    ListNode *del = temp->next;
    temp->next = del->next;
    delete del;
    cnt--;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj=new MyLinkedList();
 * int param_1=obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
/*tc:O(n) && sc:O(1)*/