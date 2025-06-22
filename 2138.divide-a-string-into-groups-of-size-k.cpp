class Solution
{
public:
  vector<string> divideString(string s, int k, char fill)
  {
    vector<string> ans;
    int n = s.length();
    string str;
    for (int i = 0; i < n; i++)
    {
      str += s[i];
      if ((i + 1) % k == 0)
      {
        ans.push_back(str);
        str = "";
      }
    }
    if (!str.empty())
    {
      while (str.length() < k)
      {
        str += fill;
      }
      ans.push_back(str);
    }
    return ans;
  }
};