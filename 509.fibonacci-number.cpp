class Solution
{ // recursive dp solution
public:
  int recur(vector<int> &dp, int n)
  {
    if (n <= 1)
    {
      return n;
    }
    if (dp[n] != -1)
      return dp[n];
    return dp[n] = recur(dp, n - 1) + recur(dp, n - 2);
  }
  int fib(int n)
  {
    vector<int> dp(n + 1, -1);
    return recur(dp, n);
  }
};
class Solution
{ // iterative dp optimal solution
public:
  int fib(int n)
  {
    if (n <= 1)
    {
      return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
      c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};