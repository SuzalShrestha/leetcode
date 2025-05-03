class Solution
{
public:
  int numIdenticalPairs(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    int res = 0;
    for (int num : nums)
    {
      mp[num]++;
    }
    for (int num : nums)
    {
      mp[num] -= 1;
      res += mp[num];
    }
    return res;
  }
};