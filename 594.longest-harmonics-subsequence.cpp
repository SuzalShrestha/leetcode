class Solution
{
public:
  int findLHS(vector<int> &nums)
  {
    unordered_map<int, int> freq;
    for (int num : nums)
    {
      freq[num]++;
    }
    int result = 0;
    for (auto &[num, cnt] : freq)
    {
      if (freq.count(num + 1))
      {
        result = max(result, cnt + freq[num + 1]);
      }
    }
    return result;
  }
};