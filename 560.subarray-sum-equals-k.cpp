class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    unordered_map<int, int> prefixFreq;
    prefixFreq[0] = 1;
    int prefixsum = 0, cnt = 0;
    for (int num : nums)
    {
      prefixsum += num;
      if (prefixFreq.find(prefixsum - k) != prefixFreq.end())
      {
        cnt += prefixFreq[prefixsum - k];
      }
      prefixFreq[prefixsum]++;
    }
    return cnt;
  }
};