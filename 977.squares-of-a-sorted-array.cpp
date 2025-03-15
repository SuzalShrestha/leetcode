class Solution
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> res(n, 0);
    for (int i = r; i >= 0; i--)
    {
      int val;
      if (abs(nums[l]) > abs(nums[r]))
      {
        val = nums[l];
        l++;
      }
      else
      {
        val = nums[r];
        r--;
      }
      res[i] = val * val;
    }
    return res;
  }
};