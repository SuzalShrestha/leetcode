class Solution
{
public:
  int findupperbound(vector<int> &arr, int target)
  {
    int n = arr.size();
    int high = n - 1;
    int low = 0;
    int ans = -1;
    while (high >= low)
    {
      int mid = low + (high - low) / 2;
      // only diff between lower and upper bound
      if (arr[mid] > target)
      {
        ans = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    // returns index of the item
    return ans;
  }
};
class Solution
{
public:
  int findupperbound(vector<int> &arr, int target)
  {
    int up = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return up;
  }
};