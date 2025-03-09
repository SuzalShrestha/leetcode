class Solution
{
public:
  void dfs(int i, vector<vector<int>> &res, vector<int> &curr,
           vector<int> &nums)
  {
    if (i >= nums.size())
    {
      res.push_back(curr);
      return;
    }
    curr.push_back(nums[i]);
    dfs(i + 1, res, curr, nums);
    curr.pop_back();
    dfs(i + 1, res, curr, nums);
  }
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> res;
    vector<int> curr;
    dfs(0, res, curr, nums);
    return res;
  }
};
class Solution
{ // using bit manipulation
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    int n = nums.size();
    int subsets = 1 << n;
    vector<vector<int>> res;
    for (int num = 0; num < subsets; num++)
    {
      vector<int> arr;
      for (int i = 0; i < n; i++)
      {
        if (num & (1 << i))
          arr.push_back(nums[i]);
      }
      res.push_back(arr);
    }
    return res;
  }
};