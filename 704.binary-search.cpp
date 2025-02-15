class Solution // array should be sorted for binary search
{              // iterative solution
public:
  int search(vector<int> &nums, int target)
  {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
      {
        high = mid - 1;
      }
      else
        low = mid + 1;
    }
    return -1;
  }
};
class Solution
{ // recursive solution
public:
  int bs(vector<int> &nums, int target, int low, int high)
  {
    if (high < low)
      return -1;
    int mid = (low + high) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
      return bs(nums, target, low, mid - 1);
    else
      return bs(nums, target, mid + 1, high);
  }
  int search(vector<int> &nums, int target)
  {
    int low = 0;
    int high = nums.size() - 1;
    return bs(nums, target, low, high);
  }
};