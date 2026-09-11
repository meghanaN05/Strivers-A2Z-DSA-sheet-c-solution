#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  class Node
  {
  public:
    Node *links[26];
    bool flag;
    Node()
    {
      for (int i = 0; i < 26; i++)
      {
        links[i] = NULL;
      }
      flag = false;
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
    void SetEnd()
    {
      flag = true;
    }
    bool getEnd()
    {
      return flag;
    }
  };
  string longestValidWord(vector<string> &words)
  {
    // code here
    Node *root = new Node();
    for (auto word : words)
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
      }
      node->SetEnd();
    }
    string ans = "";
    for (auto word : words)
    {
      Node *node = root;
      bool valid = true;
      for (int i = 0; i < word.size(); i++)
      {
        node = node->get(word[i]);
        if (!node->getEnd())
        {
          valid = false;
          break;
        }
      }
      if (valid)
      {
        if (word.size() > ans.size())
          ans = word;
        if (word.size() == ans.size() && word < ans)
          ans = word;
      }
    }
    return ans;
  }
};
/*
Time Complexity:
O(T) = O(N × L)

Space Complexity:
O(T × 26) = O(T) = O(N × L)
*/