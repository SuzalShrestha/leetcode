class Solution
{
public:
  bool divideArray(vector<int> &nums)
  {
    map<int, int> mp;
    for (int num : nums)
    {
      mp[num]++;
    }
    for (auto it : mp)
    {
      if (it.second % 2) // if odd
        return false;
    }
    return true;
  }
};
class Solution
{ // space optimized
public:
  bool divideArray(vector<int> &nums)
  {
    set<int> odd_set;
    for (int num : nums)
    {
      if (odd_set.find(num) == odd_set.end())
        odd_set.insert(num);
      else
        odd_set.erase(num);
    }
    return odd_set.size() == 0;
  }
};