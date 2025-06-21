class Solution
{
public:
  int minimumDeletions(string word, int k)
  {
    vector<int> freq(26, 0);
    int ans = word.length();
    for (char &ch : word)
    {
      freq[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
      int del = 0;
      for (int j = 0; j < 26; j++)
      {
        if (j == i)
          continue;
        if (freq[j] < freq[i])
        {
          del += freq[j];
        }
        else if (abs(freq[j] - freq[i]) > k)
        {
          del += abs(freq[j] - freq[i] - k);
        }
      }
      ans = min(ans, del);
    }
    return ans;
  }
};