class Solution
{
public:
  bool isSym(string s, int n)
  {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; i++)
    {
      sum1 += s[i] - '0';
    }
    for (int i = n / 2; i < n; i++)
    {
      sum2 += s[i] - '0';
    }
    return sum1 == sum2;
  }
  int countSymmetricIntegers(int low, int high)
  {
    int cnt = 0;
    for (int i = low; i <= high; i++)
    {
      string curr = to_string(i);
      int n = curr.length();
      if (n % 2 == 0)
      {
        if (isSym(curr, n))
          cnt++;
      }
    }
    return cnt;
  }
};
class Solution
{
public:
  int countSymmetricIntegers(int low, int high)
  {
    int res = 0;
    for (int a = low; a <= high; a++)
    {
      if (a < 100 && a % 11 == 0)
        res++;
      else if (1000 <= a && a < 10000)
      {
        int left = a / 1000 + (a % 1000) / 100;
        int right = a % 10 + (a % 100) / 10;
        if (left == right)
          res++;
      }
    }
    return res;
  }
};