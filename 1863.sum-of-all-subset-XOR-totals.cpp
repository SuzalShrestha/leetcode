class Solution
{
public:
  int dfs(int i, int total, vector<int> &nums)
  {
    if (i == nums.size())
      return total;
    return dfs(i + 1, total ^ nums[i], nums) + dfs(i + 1, total, nums);
  }
  int subsetXORSum(vector<int> &nums) { return dfs(0, 0, nums); }
};