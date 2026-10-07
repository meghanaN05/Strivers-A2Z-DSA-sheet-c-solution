#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<string>> ans;
  unordered_map<string, vector<string>> parent;
  unordered_map<string, int> dist;
  string beginWord, endWord;

  void dfs(string word, vector<string> &path)
  {
    if (word == beginWord)
    {
      vector<string> temp = path;
      reverse(temp.begin(), temp.end());
      ans.push_back(temp);
      return;
    }

    for (auto &p : parent[word])
    {
      path.push_back(p);
      dfs(p, path);
      path.pop_back();
    }
  }

  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    this->beginWord = beginWord;
    this->endWord = endWord;
    unordered_set<string> st(wordList.begin(), wordList.end());
    if (!st.count(endWord))
      return {};

    queue<string> q;
    q.push(beginWord);
    dist[beginWord] = 0;
    int L = beginWord.size();
    while (!q.empty())
    {
      string word = q.front();
      q.pop();
      int step = dist[word];
      string temp = word;

      for (int i = 0; i < L; i++)
      {
        char orig = temp[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          temp[i] = ch;
          if (!st.count(temp))
            continue;

          if (!dist.count(temp))
          {
            dist[temp] = step + 1;
            q.push(temp);
          }
          if (dist[temp] == step + 1)
            parent[temp].push_back(word);
        }
        temp[i] = orig;
      }
    }

    if (!dist.count(endWord))
      return {};

    vector<string> path;
    path.push_back(endWord);
    dfs(endWord, path);
    return ans;
  }
};