
#include <bitset>/stdc++.h>
using namespace std;
class Trie
{
public:
  class Node
  {
  public:
    Node *links[26];
    bool flag;
    Node()
    {
      flag = false;
      for (int i = 0; i < 26; i++)
        links[i] = NULL;
    }
    bool contains(char ch)
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
    bool isEnd()
    {
      return flag;
    }
    void setEnd()
    {
      flag = true;
    }
  };
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
      if (!node->contains(ch))
      {
        node->put(ch, new Node());
      }
      node = node->get(ch);
    }
    node->setEnd();
  }

  bool search(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      char ch = word[i];
      if (!node->contains(ch))
      {
        return false;
      }
      node = node->get(ch);
    }
    return node->isEnd();
  }

  bool startsWith(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      char ch = word[i];
      if (!node->contains(ch))
      {
        return false;
      }
      node = node->get(ch);
    }
    return true;
  }
};

/**
 * | Operation            | Time     |
| -------------------- | -------- |
| `insert(word)`       | **O(L)** |
| `search(word)`       | **O(L)** |
| `startsWith(prefix)` | **O(L)** |

 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 *
 */