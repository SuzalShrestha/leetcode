class Solution
{
public:
  int divide(int dividend, int divisor)
  {
    if (dividend == divisor)
      return 1;
    bool sign = true;
    if (dividend >= 0 && divisor < 0)
      sign = false;
    else if (dividend < 0 && divisor >= 0)
      sign = false;
    long n = abs((long)dividend);
    long d = abs((long)divisor);
    long ans = 0;
    while (d <= n)
    {
      int cnt = 0;
      while ((d << (cnt + 1)) <= n)
        cnt++;
      ans += (1 << cnt);
      n -= d << cnt;
    }
    if (ans == (1 << 31) && sign)
      return INT_MAX;
    if (ans == (1 << 31) && !sign)
      return INT_MIN;
    if (!sign)
      return ans = -ans;
    return ans;
  }
};