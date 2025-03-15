class Solution
{ // using binary search optimal solution
public:
  int isValid(vector<int> &nums, int k, int capability)
  {
    int cnt = 0;
    int i = 0;
    while (i < nums.size())
    {
      if (nums[i] <= capability)
      {
        i += 2;
        cnt++;
      }
      else
        i++;
      if (cnt == k)
        break;
    }
    return k == cnt;
  }
  int minCapability(vector<int> &nums, int k)
  {
    int l = 1;
    int r = *max_element(nums.begin(), nums.end());
    int res = INT_MAX;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (isValid(nums, k, mid))
      {
        r = mid - 1;
        res = mid;
      }
      else
        l = mid + 1;
    }
    return res;
  }
};