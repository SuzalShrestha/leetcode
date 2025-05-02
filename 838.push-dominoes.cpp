class Solution
{
public:
  string pushDominoes(string dominoes)
  {
    int n = dominoes.length();
    string res = "";
    vector<int> leftClosestR(n);
    vector<int> rightClosestL(n);
    for (int i = 0; i < n; i++)
    {
      if (dominoes[i] == 'R')
      {
        leftClosestR[i] = i;
      }
      else if (dominoes[i] == '.')
      {
        leftClosestR[i] = i > 0 ? leftClosestR[i - 1] : -1;
      }
      else
      {
        leftClosestR[i] = -1;
      }
    }
    for (int i = n - 1; i >= 0; i--)
    {
      if (dominoes[i] == 'L')
      {
        rightClosestL[i] = i;
      }
      else if (dominoes[i] == '.')
      {
        rightClosestL[i] = i < n - 1 ? rightClosestL[i + 1] : -1;
      }
      else
      {
        rightClosestL[i] = -1;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (dominoes[i] == 'L' || dominoes[i] == 'R')
      {
        res += dominoes[i];
        continue;
      }
      int distRightL = abs(rightClosestL[i] - i);
      int distLeftR = abs(i - leftClosestR[i]);
      if (leftClosestR[i] == rightClosestL[i])
      {
        res += '.';
      }
      else if (rightClosestL[i] == -1)
      {
        res += 'R';
      }
      else if (leftClosestR[i] == -1)
      {
        res += 'L';
      }
      else if (distRightL == distLeftR)
      {
        res += '.';
      }
      else
      {
        res += distRightL < distLeftR ? 'L' : 'R';
      }
    }
    return res;
  }
};
class Solution
{
public:
  string pushDominoes(string dominoes)
  {
    int n = dominoes.length();
    string res = "";
    vector<int> leftClosestR(n);
    vector<int> rightClosestL(n);
    for (int i = 0; i < n; i++)
    {
      if (dominoes[i] == 'R')
      {
        leftClosestR[i] = i;
      }
      else if (dominoes[i] == '.')
      {
        leftClosestR[i] = i > 0 ? leftClosestR[i - 1] : -1;
      }
      else
      {
        leftClosestR[i] = -1;
      }
    }
    for (int i = n - 1; i >= 0; i--)
    {
      if (dominoes[i] == 'L')
      {
        rightClosestL[i] = i;
      }
      else if (dominoes[i] == '.')
      {
        rightClosestL[i] = i < n - 1 ? rightClosestL[i + 1] : -1;
      }
      else
      {
        rightClosestL[i] = -1;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (dominoes[i] == 'L' || dominoes[i] == 'R')
      {
        res += dominoes[i];
        continue;
      }
      if (rightClosestL[i] == -1 && leftClosestR[i] == -1)
      {
        res += '.';
      }
      else if (rightClosestL[i] == -1)
      {
        res += 'R';
      }
      else if (leftClosestR[i] == -1)
      {
        res += 'L';
      }
      else
      {
        int r = abs(rightClosestL[i] - i);
        int l = abs(i - leftClosestR[i]);
        if (r < l)
        {
          res += 'L';
        }
        else if (r == l)
        {
          res += '.';
        }
        else
        {
          res += 'R';
        }
      }
    }
    return res;
  }
};