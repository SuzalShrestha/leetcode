class Solution
{
public:
  int minOperations(vector<vector<int>> &grid, int x)
  {
    vector<int> nums;
    int gridSum = 0;
    for (auto &g : grid)
    {
      for (int it : g)
      {
        if (it % x != grid[0][0] % x)
          return -1;
        nums.push_back(it);
        gridSum += it;
      }
    }
    sort(nums.begin(), nums.end());
    int prefixSum = 0;
    int res = gridSum;
    int len = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
      int curr = nums[i];
      int leftcost = i * curr - prefixSum;
      int rightcost = gridSum - prefixSum - ((len - i) * curr);
      int operations = (leftcost + rightcost) / x;
      prefixSum += curr;
      res = min(operations, res);
    }
    return res;
  }
};