class Solution
{
public:
  bool canCross(vector<int> &stones)
  {
    unordered_map<int, unordered_set<int>> mp;
    mp[1] = {1};
    for (int i = 1; i < stones.size(); ++i)
    {
      for (auto jumpSize : mp[stones[i]])
      {
        mp[stones[i] + jumpSize].insert(jumpSize);
        mp[stones[i] + jumpSize - 1].insert(jumpSize - 1);
        mp[stones[i] + jumpSize + 1].insert(jumpSize + 1);
      }
    }
    return mp[stones.back()].size() != 0;
  }
};