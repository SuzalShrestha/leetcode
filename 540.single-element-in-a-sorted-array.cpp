class Solution
{ // bruteforce solution O(n)
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (i == 0)
      {
        if (nums[i + 1] != nums[i])
          return nums[i];
      }
      else if (i == n - 1)
      {
        if (nums[i] != nums[i - 1])
          return nums[i];
      }
      else if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
      {
        return nums[i];
      }
    }
    return -1;
  }
};
class Solution
{ // better solution using xor O(n)
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int xor1 = 0;
    for (auto i : nums)
      xor1 ^= i;
    return xor1;
  }
};
class Solution
{ // optimal solution O(logn) using single element project of even and odd index
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    int high = n - 1, low = 0;
    while (low < high)
    {
      int mid = low + (high - low) / 2;
      if (nums[mid] == nums[mid ^ 1])
      {
        low = mid + 1;
      }
      else
      {
        high = mid;
      }
    }
    return nums[low];
  }
};
class Solution
{ // optimal solution
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    if (nums[0] != nums[1])
      return nums[0];
    if (nums[n - 1] != nums[n - 2])
      return nums[n - 1];
    int high = n - 2, low = 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        return nums[mid];

      if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
          (mid % 2 == 1 && nums[mid] == nums[mid - 1]))

        low = mid + 1;

      else
        high = mid - 1;
    }
    // dummy index
    return -1;
  }
};