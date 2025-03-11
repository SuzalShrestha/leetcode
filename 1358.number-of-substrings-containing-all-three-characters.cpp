class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    map<char, int> mp;
    int l = 0;
    int res = 0;
    int n = s.size();
    for (int r = 0; r < s.size(); r++)
    {
      mp[s[r]]++;
      while (mp.size() == 3)
      {
        res += n - r;
        mp[s[l]]--;
        if (mp[s[l]] == 0)
          mp.erase(s[l]);
        l++;
      }
    }
    return res;
  }
};