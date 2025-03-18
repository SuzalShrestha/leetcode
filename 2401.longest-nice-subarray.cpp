class Solution
{
public:
  int longestNiceSubarray(vector<int> &nums)
  {
    int res = 0, l = 0, curr = 0;
    for (int r = 0; r < nums.size(); r++)
    {
      while (curr & nums[r])
      {
        curr ^= nums[l];
        l++;
      }
      res = max(res, r - l + 1);
      curr = curr | nums[r];
    }
    return res;
  }
};