#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  Node *links[26];
  int Endswith;
  int cntprefix;
  Node()
  {
    for (int i = 0; i < 26; i++)
      links[i] = NULL;
    Endswith = 0;
    cntprefix = 0;
  }
  bool containskey(char ch)
  {
    return links[ch - 'a'] != NULL;
  }
  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node;
  }
  Node *get(char ch)
  {
    return links[ch - 'a'];
  }
  void increaseEnd()
  {
    Endswith++;
  }
  void increaseprefix()
  {
    cntprefix++;
  }
  void deleteEnd()
  {
    Endswith--;
  }
  void reduceprefix()
  {
    cntprefix--;
  }
  int getEnd()
  {
    return Endswith;
  }
  int getprefix()
  {
    return cntprefix;
  }
};
class Trie
{
public:
  Node *root;
  Trie()
  {
    root = new Node();
  }
  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      char ch = word[i];
      if (!node->containskey(ch))
      {
        node->put(ch, new Node());
      }
      node = node->get(ch);
      node->increaseprefix();
    }
    node->increaseEnd();
  }
  int countWordsEqualTo(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      char ch = word[i];
      if (!node->containskey(ch))
      {
        return 0;
      }
      node = node->get(ch);
    }
    return node->getEnd();
  }
  int countWordsStartingWith(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      char ch = word[i];
      if (!node->containskey(ch))
      {
        return 0;
      }
      node = node->get(ch);
    }
    return node->getprefix();
  }
  void erase(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      char ch = word[i];
      node = node->get(ch);
      node->reduceprefix();
    }
    node->deleteEnd();
  }
};
/*

Let $L$ be the length of the word.

| Operation | Time Complexity | Extra Space |
|---|---:|---:|
| `insert(word)` | $O(L)$ | $O(1)$ |
| `countWordsEqualTo(word)` | $O(L)$ | $O(1)$ |
| `countWordsStartingWith(word)` | $O(L)$ | $O(1)$ |
| `erase(word)` | $O(L)$ | $O(1)$ |

The trie’s total storage is:

- $O(P)$ nodes, where $P$ is the number of distinct prefixes.
- In the worst case, for $N$ words of maximum length $L$: $O(NL)$ nodes.
- Each node contains 26 pointers, so the constant factor is $26$.

Note: `erase()` assumes the word exists. If it does not, `node` can become `nullptr` and cause an error.*/