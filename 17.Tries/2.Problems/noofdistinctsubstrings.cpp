#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  Node *links[26];

  Node()
  {
    for (int i = 0; i < 26; i++)
    {
      links[i] = NULL;
    }
  }

  bool containskey(char ch)
  {
    return links[ch - 'a'] != NULL;
  }

  Node *get(char ch)
  {
    return links[ch - 'a'];
  }

  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node;
  }
};

int distinctSubstring(string &word)
{

  Node *root = new Node();
  int cnt = 0;
  for (int i = 0; i < word.size(); i++)
  {
    Node *node = root;
    for (int j = i; j < word.size(); j++)
    {
      char ch = word[j];
      if (!node->containskey(ch))
      {
        cnt++;
        node->put(ch, new Node());
      }

      node = node->get(ch);
    }
  }

  return cnt;
}
/*
Time Complexity  : O(N²)
Space Complexity : O(N²)*/