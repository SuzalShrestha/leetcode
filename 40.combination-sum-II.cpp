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
class Solution
{
public:
  void getCombSum2(int i, vector<int> &candidates, int target,
                   vector<vector<int>> &res, vector<int> &curr)
  {
    if (target == 0)
    {
      res.push_back(curr);
      return;
    }
    for (int j = i; j < candidates.size(); j++)
    {
      if (j > i && candidates[j] == candidates[j - 1])
        continue;
      if (candidates[j] > target)
        break;
      curr.push_back(candidates[j]);
      getCombSum2(j + 1, candidates, target - candidates[j], res, curr);
      curr.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    vector<vector<int>> res;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    getCombSum2(0, candidates, target, res, curr);
    return res;
  }
};