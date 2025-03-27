class Solution
{
public:
  int minimumIndex(vector<int> &nums)
  {
    unordered_map<int, int> lmp;
    unordered_map<int, int> rmp;
    for (auto &it : nums)
      rmp[it]++;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      lmp[nums[i]]++;
      rmp[nums[i]]--;
      int leftlen = i + 1;
      int rightlen = n - i - 1;
      if (2 * lmp[nums[i]] > leftlen && 2 * rmp[nums[i]] > rightlen)
        return i;
    }
    return -1;
  }
};