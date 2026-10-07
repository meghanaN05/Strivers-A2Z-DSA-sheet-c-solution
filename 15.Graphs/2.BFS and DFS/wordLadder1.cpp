#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    queue<string> q;
    unordered_set<string> st(wordList.begin(), wordList.end());
    if (st.find(endWord) == st.end())
      return 0;
    int cnt = 1;
    q.push(beginWord);
    st.erase(beginWord);
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        string word = q.front();
        q.pop();
        if (word == endWord)
          return cnt;
        for (int i = 0; i < word.size(); i++)
        {
          char ch = word[i];
          for (char c = 'a'; c <= 'z'; c++)
          {
            word[i] = c;
            if (st.find(word) != st.end())
            {

              st.erase(word);
              q.push(word);
            }
            word[i] = ch;
          }
        }
      }
      cnt++;
    }
    return 0;
  }
};