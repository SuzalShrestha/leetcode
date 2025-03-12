class Solution
{
public:
  int maximumCount(vector<int> &nums)
  {
    int negcnt = 0;
    int poscnt = 0;
    for (auto num : nums)
    {
      if (num < 0)
        negcnt++;
      if (num > 0)
        poscnt++;
    }
    return max(negcnt, poscnt);
  }
};
class Solution
{ // optimal solution
  // using binary search as array is sorted
public:
  int lowerBound(vector<int> &nums)
  {
    int start = 0, end = nums.size() - 1;
    int index = nums.size();
    while (start <= end)
    {
      int mid = (start + end) / 2;
      if (nums[mid] < 0)
      {
        start = mid + 1;
      }
      else if (nums[mid] >= 0)
      {
        end = mid - 1;
        index = mid;
      }
    }
    return index;
  }
  int upperBound(vector<int> &nums)
  {
    int start = 0, end = nums.size() - 1;
    int index = nums.size();
    while (start <= end)
    {
      int mid = (start + end) / 2;
      if (nums[mid] <= 0)
      {
        start = mid + 1;
      }
      else if (nums[mid] > 0)
      {
        end = mid - 1;
        index = mid;
      }
    }
    return index;
  }
  int maximumCount(vector<int> &nums)
  {
    int poscnt = nums.size() - upperBound(nums);
    int negcnt = lowerBound(nums);
    return max(poscnt, negcnt);
  }
};