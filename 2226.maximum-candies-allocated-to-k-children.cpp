class Solution
{
public:
  int isValid(int num, vector<int> &candies, int res)
  {
    long long sum = 0;
    for (int it : candies)
    {
      sum += it / num;
    }
    return sum >= res;
  }
  int maximumCandies(vector<int> &candies, long long k)
  {
    long long sum = 0;
    for (int c : candies)
    {
      sum += c;
    }
    if (sum < k)
      return 0;
    int l = 1;
    long long r = sum / k;
    int res = INT_MIN;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (isValid(mid, candies, k))
      {
        l = mid + 1;
        res = max(res, mid);
      }
      else
        r = mid - 1;
    }
    return r;
  }
};