#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};
int main()
{
  Node *head = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);
  head->next = second;
  second->next = third;
  return 0;
}
// doubly linked list
struct Node
{
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

int main()
{
  // 2. Initialize nodes
  Node *head = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);

  // 3. Connect nodes bidirectionally
  head->next = second;
  second->prev = head;

  second->next = third;
  third->prev = second;

  return 0;
}
// circular linkedlist
struct Node
{
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

int main()
{
  // 2. Initialize nodes
  Node *head = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);

  // 3. Connect nodes
  head->next = second;
  second->next = third;

  // 4. Make it circular by pointing the last node back to head
  third->next = head;

  return 0;
}
/*tc:O(n) && sc:O(1)*/