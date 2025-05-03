class Solution
{
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
  {
    int n = tops.size();
    int res = INT_MAX;
    for (int i = 1; i < 7; i++)
    {
      int topswap = 0;
      int bottomswap = 0;
      bool possible = true;
      for (int j = 0; j < n; j++)
      {
        if (tops[j] != i && bottoms[j] != i)
        {
          possible = false;
          break;
        }
        if (tops[j] != i && bottoms[j] == i)
        {
          topswap++;
        }
        else if (bottoms[j] != i && tops[j] == i)
        {
          bottomswap++;
        }
      }
      if (possible)
      {
        res = min(res, min(topswap, bottomswap));
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};