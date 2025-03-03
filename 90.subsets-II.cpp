class Solution
{ // only works if sorted
public:
  void dfs(int i, vector<int> &nums, vector<vector<int>> &res,
           vector<int> &curr)
  {
    if (i == nums.size())
    {
      res.push_back(curr);
      return;
    }
    curr.push_back(nums[i]);
    dfs(i + 1, nums, res, curr);
    curr.pop_back();
    while (i + 1 < nums.size() && nums[i] == nums[i + 1])
      i++;
    dfs(i + 1, nums, res, curr);
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    vector<vector<int>> res;
    vector<int> curr;
    sort(nums.begin(), nums.end());
    dfs(0, nums, res, curr);
    return res;
  }
};
class Solution
{
public:
  void dfs(int i, vector<int> &nums, vector<vector<int>> &res,
           vector<int> &curr)
  {
    res.push_back(curr);
    for (int j = i; j < nums.size(); j++)
    {
      if (j != i && nums[j] == nums[j - 1])
        continue;
      curr.push_back(nums[j]);
      dfs(j + 1, nums, res, curr);
      curr.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    vector<vector<int>> res;
    vector<int> curr;
    sort(nums.begin(), nums.end());
    dfs(0, nums, res, curr);
    return res;
  }
};