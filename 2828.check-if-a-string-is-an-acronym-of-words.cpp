class Solution
{
public:
  bool isAcronym(vector<string> &words, string s)
  {
    int w = words.size();
    int n = s.length();
    if (w != n)
      return false;
    for (int i = 0; i < n; i++)
    {
      if (words[i][0] - '0' != s[i] - '0')
        return false;
    }
    return true;
  }
};