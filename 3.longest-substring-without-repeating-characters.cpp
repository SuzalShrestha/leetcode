class Solution
{
public:
  int lengthOfLongestSubstring(string str)
  {
    int l = 0;
    int res = 0;
    unordered_set<char> s;
    for (int r = 0; r < str.size(); r++)
    {
      while (s.find(str[r]) != s.end())
      {
        s.erase(str[l]);
        l++;
      }
      s.insert(str[r]);
      res = max(res, r - l + 1);
    }
    return res;
  }
};