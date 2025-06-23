class Solution
{
public:
  string tobaseK(long long num, int k)
  {
    string res = "";
    while (num > 0)
    {
      res += to_string(num % k);
      num /= k;
    }
    reverse(begin(res), end(res));
    return res;
  }
  bool isPalindrome(string s)
  {
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
      if (s[i] != s[j])
      {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
  long long kMirror(int k, int n)
  {
    long long sum = 0;
    int L = 1; // create 1 length numbers
    while (n > 0)
    {
      int halfLen = (L + 1) / 2;
      long long min_num = pow(10, halfLen - 1);
      long long max_num = pow(10, halfLen) - 1;
      for (long long num = min_num; num <= max_num; num++)
      {
        string first_half = to_string(num);
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        string pali = "";
        if (L % 2 == 0)
        {
          pali = first_half + second_half;
        }
        else
        {
          pali = first_half + second_half.substr(1);
        }
        long long pali_num = stoll(pali);
        string baseK = tobaseK(pali_num, k);
        if (isPalindrome(baseK))
        {
          sum += pali_num;
          n--;
          if (n == 0)
            break;
        }
      }
      L++;
    }
    return sum;
  }
};