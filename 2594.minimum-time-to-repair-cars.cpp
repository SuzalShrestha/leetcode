class Solution
{
public:
  int isValid(vector<int> &ranks, int cars, long long time)
  {
    long long totalcar = 0;
    for (int rank : ranks)
    {
      totalcar += sqrt(time / rank);
    }
    return totalcar >= cars;
  }
  long long repairCars(vector<int> &ranks, int cars)
  {
    int maxele = *max_element(ranks.begin(), ranks.end());
    long long maxtime = maxele * pow(cars, 2);
    long long l = 1,
              r = maxtime;
    while (l <= r)
    {
      long long mid = l + (r - l) / 2;
      if (isValid(ranks, cars, mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};