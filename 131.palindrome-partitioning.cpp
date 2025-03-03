class Solution
{
public:
  bool isPalindrome(string s, int start, int end)
  {
    while (start <= end)
    {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
  void path(int index, string s, vector<vector<string>> &res,
            vector<string> &curr)
  {
    if (index == s.size())
    {
      res.push_back(curr);
      return;
    }
    for (int i = index; i < s.size(); i++)
    {
      if (isPalindrome(s, index, i))
      {
        curr.push_back(s.substr(index, i - index + 1));
        path(i + 1, s, res, curr);
        curr.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> res;
    vector<string> curr;
    path(0, s, res, curr);
    return res;
  }
};