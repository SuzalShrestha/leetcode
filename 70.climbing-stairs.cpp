class Solution
{ // dp solution
public:
  int climbStairs(int n)
  {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    vector<int> mem(n, -1);
    mem[0] = 1;
    mem[1] = 2;
    for (int i = 2; i < n; i++)
    {
      mem[i] = mem[i - 1] + mem[i - 2];
    }
    return mem[n - 1];
  }
};