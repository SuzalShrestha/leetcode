class Solution
{
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes)
  {
    int n = dominoes.size();
    vector<int> mp(100);
    int res = 0;
    for (auto &d : dominoes)
    {
      int s = min(d[0], d[1]);
      int l = max(d[0], d[1]);
      int key = 10 * s + l;
      res += mp[key];
      mp[key]++;
    }
    return res;
  }
};