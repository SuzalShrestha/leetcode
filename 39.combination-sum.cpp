class Solution // recursive solution
{              // generalized base case
public:
  void getCombSum(int i, vector<int> &candidates, vector<vector<int>> &res,
                  vector<int> &curr, int target)
  {
    if (i == candidates.size())
    {
      if (target == 0)
        res.push_back(curr);
      return;
    }
    if (target >= candidates[i])
    {
      curr.push_back(candidates[i]);
      getCombSum(i, candidates, res, curr, target - candidates[i]);
      curr.pop_back();
    }
    getCombSum(i + 1, candidates, res, curr, target);
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<vector<int>> res;
    vector<int> curr;
    getCombSum(0, candidates, res, curr, target);
    return res;
  }
};
class Solution
{ // specific base case
public:
  void getCombSum(int i, vector<int> &candidates, vector<vector<int>> &res,
                  vector<int> &curr, int target)
  {
    if (target == 0)
    {
      res.push_back(curr);
      return;
    }
    if (i == candidates.size() || target < 0)
      return;
    if (target >= candidates[i])
    {
      curr.push_back(candidates[i]);
      getCombSum(i, candidates, res, curr, target - candidates[i]);
      curr.pop_back();
    }
    getCombSum(i + 1, candidates, res, curr, target);
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<vector<int>> res;
    vector<int> curr;
    getCombSum(0, candidates, res, curr, target);
    return res;
  }
};