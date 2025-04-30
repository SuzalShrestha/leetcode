class Solution
{
public:
  int findNumbers(vector<int> &nums)
  {
    int result = 0;
    for (int num : nums)
    {
      int digitcnt = (int)floor(log10(num)) + 1;
      if ((digitcnt & 1) == 0)
      {
        result++;
      }
    }
    return result;
  }
};
class Solution
{
public:
  int findNumbers(vector<int> &nums)
  {
    int result = 0;
    for (int num : nums)
    {
      int digitcnt = (int)floor(log10(num)) + 1;
      if (digitcnt % 2 == 0)
      {
        result++;
      }
    }
    return result;
  }
};
class Solution
{
public:
  int findNumbers(vector<int> &nums)
  {
    int res = 0;
    for (int num : nums)
    {
      if ((to_string(num).length()) % 2 == 0)
      {
        res++;
      }
    }
    return res;
  }
};
class Solution
{
public:
  // Helper function to check if the number of digits is even
  bool hasEvenDigits(int num)
  {
    int digitCount = 0;
    while (num)
    {
      digitCount++;
      num /= 10;
    }
    return (digitCount & 1) == 0;
  }

  int findNumbers(vector<int> &nums)
  {
    // Counter to count the number of even digit integers
    int evenDigitCount = 0;

    for (int num : nums)
    {
      if (hasEvenDigits(num))
        evenDigitCount++;
    }

    return evenDigitCount;
  }
};