class Solution
{ // optimal solution using greedy approach
public:
  void flip(vector<int> &nums, int index)
  {
    if (nums[index] == 0)
      nums[index] = 1;
    else
      nums[index] = 0;
  }
  int minOperations(vector<int> &nums)
  {
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
      if (nums[i] == 0)
      {
        flip(nums, i);
        flip(nums, i + 1);
        flip(nums, i + 2);
        res++;
      }
    }
    if (nums[n - 2] == 0 || nums[n - 1] == 0)
      return -1;
    return res;
  }
};
class Solution
{ // using xor to flip
public:
  int minOperations(vector<int> &nums)
  {
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
      if (nums[i] == 0)
      {
        nums[i] ^= 1; // flip
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        res++;
      }
    }
    if (nums[n - 2] == 0 || nums[n - 1] == 0)
      return -1;
    return res;
  }
};