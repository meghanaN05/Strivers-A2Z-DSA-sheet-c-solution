#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string findOrder(vector<string> &words)
  {
    int n = words.size();
    unordered_map<char, vector<char>> adj;
    unordered_map<char, int> indegree;
    // Step 1: Initialize indegree for all characters
    for (auto &w : words)
      for (auto &c : w)
        indegree[c] = 0;
    // Step 2: Build graph by comparing adjacent words
    for (int i = 0; i < n - 1; i++)
    {
      string w1 = words[i];
      string w2 = words[i + 1];
      int len = min(w1.size(), w2.size());
      bool found = false;

      for (int j = 0; j < len; j++)
      {
        if (w1[j] != w2[j])
        {
          adj[w1[j]].push_back(w2[j]);
          indegree[w2[j]]++;
          found = true;
          break;
        }
      }
      // invalid if prefix case (e.g., "abcd" before "ab")
      if (!found && w1.size() > w2.size())
        return "";
    }

    // Step 3: Topological Sort (Kahn’s Algorithm)
    queue<char> q;
    for (auto &p : indegree)
      if (p.second == 0)
        q.push(p.first);

    string order = "";
    while (!q.empty())
    {
      char u = q.front();
      q.pop();
      order += u;
      for (char v : adj[u])
      {
        indegree[v]--;
        if (indegree[v] == 0)
          q.push(v);
      }
    }

    // Step 4: Check for cycles (invalid order)
    if (order.size() != indegree.size())
      return "";

    return order;
  }
};