class Solution
{ // optimal solution as xor or 2 same numbers is 0 so only single number remains
public:
  int singleNumber(vector<int> &nums)
  {
    int n = nums.size();
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
      xor1 = xor1 ^ nums[i];
    }
    return xor1;
  }
};
class Solution
{ // bruteforce solution
public:
  int singleNumber(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int j = 0; j < n; j++)
      {
        if (nums[i] == nums[j])
          cnt++;
      }
      if (cnt == 1)
        return nums[i];
    }
    return -1;
  }
};
class Solution
// better solution
{ // hashing but it only works for positive integers
  // eg:[-1]->doesnot work
public:
  int singleNumber(vector<int> &nums)
  {
    int n = nums.size();
    int maxi = nums[0];
    for (int i = 0; i < n; i++)
    {
      maxi = max(nums[i], maxi);
    }
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
      hash[nums[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
      if (hash[i] == 1)
        return i;
    }
    return n;
  }
};
class Solution
{ // better solution using maps it works with negative integers
public:
  int singleNumber(vector<int> &nums)
  {
    unordered_map<int, int> a;
    for (auto x : nums)
      a[x]++;
    for (auto y : a)
      if (y.second == 1)
        return y.first;
    return -1;
  }
};