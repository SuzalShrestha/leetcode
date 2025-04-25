class Solution
{
public:
  int findsum(int i)
  {
    int sum = 0;
    while (i > 0)
    {
      sum += i % 10;
      i = i / 10;
    }
    return sum;
  }
  int countLargestGroup(int n)
  {
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
      int sum = findsum(i);
      mp[sum]++;
    }
    int largest = 0;
    for (auto it : mp)
    {
      if (it.second > largest)
      {
        largest = it.second;
      }
    }
    int cnt = 0;
    for (auto it : mp)
    {
      if (it.second == largest)
      {
        cnt++;
      }
    }
    return cnt;
  }
};