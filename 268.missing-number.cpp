class Solution
{ // bruteforce solution O(n^2)
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i <= n; i++)
    {
      bool f = false;
      for (int j = 0; j < n; j++)
      {
        if (nums[j] == i)
        {
          f = true;
          break;
        }
      }
      if (f == false)
        return i;
    }
    // this line will never executed
    // to avoid warnings
    return -1;
  }
};
class Solution
{ // better solution O(n)
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
      hash[nums[i]] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
      if (hash[i] == 0)
        return i;
    }
    return n;
  }
};
class Solution
{ // optimal solution using sum of n natural numbers formula
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    int asum = 0;
    for (auto it : nums)
      asum += it;
    return sum - asum;
  }
};
class Solution
{ // optimal xor solution better than sum for large integer eg:10^5
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i <= n; i++)
    {
      xor1 = xor1 ^ i;
    }
    for (int i = 0; i < n; i++)
    {
      xor2 = xor2 ^ nums[i];
    }
    return xor1 ^ xor2;
  }
};
class Solution
{ // more optimal solution
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n; i++)
    {
      xor1 = xor1 ^ i;
      xor2 = xor2 ^ nums[i];
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
  }
};