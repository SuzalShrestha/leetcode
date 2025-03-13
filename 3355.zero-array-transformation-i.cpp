class Solution
{
public:
  bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();
    vector<int> diff(n + 1, 0);
    for (auto &q : queries)
    {
      int li = q[0], ri = q[1];
      diff[li]++;
      diff[ri + 1]--;
    }
    for (int i = 0, sum = 0; i < n; i++)
    {
      // prefix sum
      sum += diff[i];
      if (nums[i] > sum)
        return false;
    }
    return true;
  }
};