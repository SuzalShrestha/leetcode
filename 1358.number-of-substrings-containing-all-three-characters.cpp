class Solution
{ // better solution
  // not efficient as lookup time and erasing is log(n)
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
class Solution
{ // optimal solution
  // array lookup time O(1)
public:
  int numberOfSubstrings(string s)
  {
    int n = s.size();
    int l = 0;
    int res = 0;
    vector<int> freq(3, 0);
    for (int r = 0; r < s.size(); r++)
    {
      freq[s[r] - 'a']++;
      while (freq[0] && freq[1] && freq[2])
      {
        res += n - r;
        freq[s[l] - 'a']--;
        l++;
      }
    }
    return res;
  }
};