class Solution
{
public:
  bool threeConsecutiveOdds(vector<int> &arr)
  {
    int result = 0, cnt = 0;
    for (int num : arr)
    {
      if ((num & 1) != 0)
      {
        cnt++;
      }
      else
        cnt = 0;
      if (cnt >= 3)
        return true;
    }
    return false;
  }
};
class Solution
{
public:
  bool threeConsecutiveOdds(vector<int> &arr)
  {
    int n = arr.size();
    for (int i = 0; i < n - 2; i++)
    {
      if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1)
      {
        return true;
      }
    }
    return false;
  }
};
class Solution
{
public:
  bool threeConsecutiveOdds(vector<int> &arr)
  {
    int n = arr.size();
    for (int i = 0; i < n - 2; i++)
    {
      int product = arr[i] * arr[i + 1] * arr[i + 2];
      if (product % 2 == 1)
        return true;
    }
    return false;
  }
};