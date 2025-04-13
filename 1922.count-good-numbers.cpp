class Solution
{
public:
  const int M = 1e9 + 7;
  int findpow(long long a, long long b)
  {
    if (b == 0)
      return 1;
    long long half = findpow(a, b / 2);
    long long result = (half * half) % M;
    if (b % 2 == 1)
    {
      result = (result * a) % M;
    }
    return result;
  }
  int countGoodNumbers(long long n)
  {
    long long oddindx = n / 2;
    long long evenindx = (n + 1) / 2;
    return (long long)findpow(5, evenindx) * findpow(4, oddindx) % M;
  }
};