class Solution
{
  // bruteforce solution TC->O(n!*n)
public:
  void nextPermutation(vector<int> &nums)
  {
    // find all possible permutation in sorted order
    // return the next index
    // if last index return first index array
  }
};
class Solution
{
  // better solution using cpp stl
public:
  void nextPermutation(vector<int> &nums)
  {
    next_permutation(nums.begin(), nums.end());
  }
};
class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int n = nums.size();
    int index = -1;
    // find the index where dip occurs
    for (int i = n - 2; i >= 0; i--)
    {
      if (nums[i] < nums[i + 1])
      {
        index = i;
        break;
      }
    }
    // if no dip that it is last permutation
    if (index == -1)
      return reverse(nums.begin(), nums.end());
    // find and swap the integer just greater than the index
    for (int i = n - 1; i >= 0; i--)
    {
      if (nums[i] > nums[index])
      {
        swap(nums[i], nums[index]);
        break;
      }
    }
    // reverse all integer indexed behind the dip
    reverse(nums.begin() + index + 1, nums.end());
  }
};