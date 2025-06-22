class Solution
{
public:
  int maxFrequencyElements(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    int maxcnt = 0;
    int res = 0;
    for (auto it : nums)
    {
      mp[it]++;
      maxcnt = max(maxcnt, mp[it]);
    }
    int cnt = 0;
    for (auto it : mp)
    {
      if (it.second == maxcnt)
        res += maxcnt;
    }
    return res;
  }
};