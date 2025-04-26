class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK)
  {
    int n = nums.size();
    int minindx = -1;
    int maxindx = -1;
    int culprit = -1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] > maxK || nums[i] < minK)
      {
        culprit = i;
      }
      if (nums[i] == minK)
      {
        minindx = i;
      }
      if (nums[i] == maxK)
      {
        maxindx = i;
      }
      long long smaller = min(minindx, maxindx);
      long long temp = smaller - culprit;
      ans += temp <= 0 ? 0 : temp;
    }
    return ans;
  }
};