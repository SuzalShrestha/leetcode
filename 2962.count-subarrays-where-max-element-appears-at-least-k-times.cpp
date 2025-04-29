class Solution
{ // sliding window
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
class Solution
{ // non-sliding window approach
public:
  long long countSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();
    int maxele = *max_element(nums.begin(), nums.end());
    vector<int> maxindices;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == maxele)
      {
        maxindices.push_back(i);
      }
      int size = maxindices.size();
      if (size >= k)
      {
        int lastindx = maxindices[size - k];
        res += lastindx + 1;
      }
    }
    return res;
  }
};