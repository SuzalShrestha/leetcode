class Solution
{
public:
  vector<int> partitionLabels(string s)
  {
    vector<int> res;
    int n = s.size();
    unordered_map<char, int> lastoccur;
    for (int i = 0; i < n; i++)
    {
      lastoccur[s[i]] = i;
    }
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
      end = max(end, lastoccur[s[i]]);
      if (i == end)
      {
        res.push_back(end - start + 1);
        start = i + 1;
      }
    }
    return res;
  }
};