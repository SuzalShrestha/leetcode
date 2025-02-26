class Solution
{ // recursive solution O(logn)
public:
  double myPow(double x, int n)
  {
    if (n == 0)
      return 1;
    // prevent overflow
    long long N = n;
    if (N < 0)
    {
      N = -N;
      x = 1 / x;
    }
    return N % 2 == 0 ? myPow(x * x, N / 2) : x * myPow(x, N - 1);
  }
};