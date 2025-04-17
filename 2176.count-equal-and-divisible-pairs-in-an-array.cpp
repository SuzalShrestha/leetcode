class Solution
{
public:
  int countPairs(vector<int> &nums, int k)
  {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] == nums[j] && (i * j) % k == 0)
        {
          cnt++;
        }
      }
    }
    return cnt;
  }
};
class Solution
{
public:
  int countPairs(vector<int> &nums, int k)
  {
    int n = nums.size();
    int result = 0;
    unordered_map<int, vector<int>> indicesMap;
    for (int i = 0; i < n; i++)
    {
      indicesMap[nums[i]].push_back(i);
    }
    // putting factors of k
    unordered_set<int> div;
    for (int f = 1; f * f <= k; f++)
    {
      if (k % f == 0)
      {
        div.insert(f);
        div.insert(k / f);
      }
    }
    // O(n*(log(k)+sqrt(k)))
    for (auto &[num, indices] : indicesMap)
    {
      unordered_map<int, int> factorsMap;
      for (int i : indices)
      {
        int GCD = gcd(i, k); // TC:log(k)
        int j = k / GCD;
        result += factorsMap[j];
        for (int f : div)
        {
          if (i % f == 0)
            factorsMap[f]++;
        }
      }
    }
    return result;
  }
};