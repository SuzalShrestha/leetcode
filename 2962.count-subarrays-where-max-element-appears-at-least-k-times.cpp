class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();
    int maxele = *max_element(nums.begin(), nums.end());
    long long res = 0;
    int l = 0, r = 0, cnt = 0;
    while (r < n)
    {
      if (nums[r] == maxele)
        cnt++;
      while (cnt >= k && l <= r)
      {
        res += n - r;
        if (nums[l] == maxele)
          cnt--;
        l++;
      }
      r++;
    }
    return res;
  }
};