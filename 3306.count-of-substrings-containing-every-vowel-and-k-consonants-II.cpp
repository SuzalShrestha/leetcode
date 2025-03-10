class Solution
{
public:
  long long countOfSubstrings(string word, int k)
  {
    return atleast(word, k) - atleast(word, k + 1);
  }
  long long atleast(string word, int k)
  {
    string vowel = "aeiou";
    map<char, int> vowelCount;
    int nonvowel = 0;
    int l = 0;
    long long res = 0;
    for (int r = 0; r < word.size(); r++)
    {
      if (vowel.find(word[r]) != string::npos)
        vowelCount[word[r]] += 1;
      else
        nonvowel += 1;
      while (vowelCount.size() == 5 && nonvowel >= k)
      {
        res += (word.size() - r);
        if (vowel.find(word[l]) != string::npos)
        {
          vowelCount[word[l]] -= 1;
        }
        else
        {
          nonvowel -= 1;
        }
        if (vowelCount[word[l]] == 0)
          vowelCount.erase(word[l]);
        l += 1;
      }
    }
    return res;
  }
};