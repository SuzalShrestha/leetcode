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
{ // recursive solution O(log2(n))
public:
  int bs(vector<int> &nums, int target, int low, int high)
  {
    if (high < low)
      return -1;
    int mid = low + (high - low) / 2;
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
// Note: overflow case
// If the length of array is INT_MAX then while calculating mid,
// we add 2 INT_MAX which cannot be stored in int as it overflows.
// Thus we either subtract (low+(high-low)/2) or we can use long long datatype.
// Thus the above solution is valid for only INT_MAX array length.