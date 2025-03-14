class Solution
{
public:
  int isValid(vector<int> &piles, int h, int num)
  {
    long long sum = 0;
    for (int p : piles)
    {
      sum += (p + num - 1) / num;
    }
    return sum <= h;
  }
  int minEatingSpeed(vector<int> &piles, int h)
  {
    long long sum = 0;
    for (int p : piles)
    {
      sum += p;
    }
    int l = 1, r = *max_element(piles.begin(), piles.end());
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (isValid(piles, h, mid))
      {
        r = mid - 1;
      }
      else
        l = mid + 1;
    }
    return l;
  }
};
class Solution
{
public:
  int isValid(vector<int> &piles, int h, int num)
  {
    long long sum = 0;
    for (int p : piles)
    {
      sum += (p + num - 1) / num;
    }
    return sum <= h;
  }
  int minEatingSpeed(vector<int> &piles, int h)
  {
    long long sum = 0;
    int maxele = INT_MIN;
    for (int p : piles)
    {
      sum += p;
      maxele = max(maxele, p);
    }
    int l = 1, r = maxele;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (isValid(piles, h, mid))
      {
        r = mid - 1;
      }
      else
        l = mid + 1;
    }
    return l;
  }
};