class Solution
{
public:
  long long coloredCells(int n)
  {
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
      ans += 4 * i;
    }
    return ans;
  }
};

class Solution
{
public:
  long long coloredCells(int n)
  {
    return 1LL + (((long long)n * (n - 1)) * 2);
  }
};

class Solution
{
public:
  long long coloredCells(int n)
  {
    if (n <= 1)
      return 1;
    n = n - 1;
    return 1LL + 4LL * (((long long)n * (n + 1)) / 2);
  }
};