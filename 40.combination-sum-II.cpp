class Solution
{
public:
  void getCombSum2(int i, vector<int> &candidates, int target,
                   vector<vector<int>> &res, vector<int> &curr, int sum)
  {
    if (sum == target)
    {
      res.push_back(curr);
      return;
    }
    if (i == candidates.size() || sum > target)
    {
      return;
    }
    // include item
    curr.push_back(candidates[i]);
    getCombSum2(i + 1, candidates, target, res, curr, sum + candidates[i]);
    curr.pop_back();
    while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
      i++; // skip duplicates
    // exclude item
    getCombSum2(i + 1, candidates, target, res, curr, sum);
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    vector<vector<int>> res;
    vector<int> curr;
    int sum = 0;
    sort(candidates.begin(), candidates.end()); // sorting for handling duplicates
    getCombSum2(0, candidates, target, res, curr, sum);
    return res;
  }
};