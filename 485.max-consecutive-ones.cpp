class Solution
{ // bruteforce solution O(n^2)
public:
  int findMaxConsecutiveOnes(vector<int> &nums)
  {
    int n = nums.size();
    int larg = 0;
    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int j = i; j < n; j++)
      {
        if (nums[j] == 1)
          cnt++;
        else
          break;
      }
      if (cnt > larg)
        larg = cnt;
    }
    return larg;
  }
};
class Solution
{ // better solution O(n)
public:
  int findMaxConsecutiveOnes(vector<int> &nums)
  {
    int n = nums.size();
    int larg = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 1)
      {
        cnt++;
        larg = max(cnt, larg);
      }
      else
        cnt = 0;
    }
    return larg;
  }
};