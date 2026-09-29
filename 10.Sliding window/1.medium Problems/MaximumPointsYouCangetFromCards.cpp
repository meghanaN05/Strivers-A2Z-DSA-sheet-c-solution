#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    int score = 0;
    int n = cardPoints.size();
    for (int i = 0; i < k; i++)
    {
      score += cardPoints[i];
    }
    int maxi = score;
    for (int i = 0; i < k; i++)
    {
      score -= cardPoints[k - 1 - i];
      score += cardPoints[n - 1 - i];
      maxi = max(score, maxi);
    }
    return maxi;
  }
};