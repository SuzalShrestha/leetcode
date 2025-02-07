class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int n = nums.size();
    int cnt = 1;
    if (n == 1)
      return true;
    for (int i = 1; i < 2 * n; i++)
    {
      if (nums[i % n] > nums[(i - 1) % n])
        cnt++;
      else
        cnt = 1;
      if (cnt == n)
        return true;
    }
    return false;
  }
};