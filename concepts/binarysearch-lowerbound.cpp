class Solution
{
public:
  int findlowerbound(vector<int> &arr, int target)
  {
    int n = arr.size();
    int high = n - 1;
    int low = 0;
    int ans = -1;
    while (high >= low)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] >= target)
      {
        ans = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return ans;
  }
};
class Solution
{
public:
  int findlowerbound(vector<int> &arr, int target)
  {
    int lp = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    return lp;
  }
};