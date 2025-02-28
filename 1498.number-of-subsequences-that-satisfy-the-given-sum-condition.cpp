class Solution
{
public:
  int numSubseq(vector<int> &nums, int target)
  {
    int n = nums.size();
    if (n == 1)
    {
      return (nums[0] * 2 <= target) ? 1 : 0;
    }
    sort(nums.begin(), nums.end());
    int res = 0;
    int mod = 1e9 + 7, right = nums.size() - 1;
    vector<int> power(n, 1);
    for (int i = 1; i < n; i++)
    {
      power[i] = (power[i - 1] * 2) % mod;
    }
    for (int i = 0; i < nums.size(); i++)
    {
      while (i <= right && (nums[i] + nums[right]) > target)
        right--;
      if (i <= right)
      {
        res = (res + power[right - i]) % mod;
      }
    }
    return res;
  }
};