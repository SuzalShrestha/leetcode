class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    int ans = start ^ goal;
    int cnt = 0;
    for (int i = 0; i <= 31; i++)
    {
      if (ans & (1 << i))
        cnt++;
    }
    return cnt;
  }
};
class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    int count = 0;
    while (start > 0 || goal > 0)
    {
      if ((start & 1) != (goal & 1))
        count++;
      start >>= 1;
      goal >>= 1;
    }
    return count;
  }
};
class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    int count = 0;
    int ans = start ^ goal;
    while (ans)
    {
      count += ans & 1;
      ans >>= 1;
    }
    return count;
  }
};
class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    return __builtin_popcount(start ^ goal);
  }
};
class Solution
{ // Brian Kernighan’s Algorithm
  // optimal solution
public:
  int minBitFlips(int start, int goal)
  {
    int ans = start ^ goal;
    int cnt = 0;
    while (ans)
    {
      ans &= ans - 1;
      cnt++;
    }
    return cnt;
  }
};