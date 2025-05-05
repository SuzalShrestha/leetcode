// Main formula in this question to understand is 2*f(n-1)+f(n-3)
// 1. we eliminate the overlapping subproblem which gives is 2.
// 2. two tiles f(n-1)and f(x) has answer f(n-1)*f(x)
// 3. f(n)=f(n-1)+f(n-2)+2*f(n-3)+2*f(n-4)....+2*f(0);
// 4. formula comes from f(n)-f(n-1)=f(n-1)+f(n-3);
class Solution
{ // using dp
public:
  int M = 1e9 + 7;
  int numTilings(int n)
  {
    if (n == 1 || n == 2)
      return n;
    vector<int> t(n + 1, 0);
    t[1] = 1;
    t[2] = 2;
    t[3] = 5;
    for (int i = 4; i <= n; i++)
    {
      t[i] = (2 * t[i - 1] % M + t[i - 3] % M) % M;
    }
    return t[n];
  }
};
// using recursion + dp
class Solution
{
public:
  int M = 1e9 + 7;
  int t[1001];
  int solve(int n)
  {
    if (n == 1 || n == 2)
      return n;
    if (t[n] != -1)
      return t[n];
    if (n == 3)
      return 5;
    return t[n] = (2 * solve(n - 1) % M + solve(n - 3) % M) % M;
  }
  int numTilings(int n)
  {
    memset(t, -1, sizeof(t));
    return solve(n);
  }
};