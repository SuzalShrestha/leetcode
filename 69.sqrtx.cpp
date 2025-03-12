class Solution
{
public:
  int mySqrt(int x)
  {
    int l = 1;
    int r = x;
    while (l <= r)
    {
      long long m = l + (r - l) / 2;
      long long msq = m * m;
      if (msq == x)
        return m;
      if (msq < x)
        l = m + 1;
      else
        r = m - 1;
    }
    return r;
  }
};