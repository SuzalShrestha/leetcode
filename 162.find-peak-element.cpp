class Solution
{
  // bruteforce solution
public:
  int findPeakElement(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if ((i == n - 1 || nums[i + 1] < nums[i]) &&
          (i == 0 || nums[i - 1] < nums[i]))
        return i;
    }
    return -1;
  }
};
class Solution
{
  // O(logn) solution with binary search
public:
  int findPeakElement(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return 0;
    if (nums[1] < nums[0])
      return 0;
    if (nums[n - 1] > nums[n - 2])
      return n - 1;
    int high = n - 2, low = 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
        return mid;
      else if (nums[mid + 1] > nums[mid])
      {
        low = mid + 1;
      }
      else
        high = mid - 1;
    }
    // this will never reach
    return -1;
  }
};