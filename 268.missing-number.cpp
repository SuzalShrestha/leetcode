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