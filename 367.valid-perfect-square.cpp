class Solution
{
public:
  bool isPerfectSquare(int num)
  {
    int l = 1, r = num;
    while (l <= r)
    {
      long long m = l + (r - l) / 2;
      long long msq = m * m;
      if (msq == num)
        return true;
      if (msq < num)
        l = m + 1;
      else
        r = m - 1;
    }
    return false;
  }
};