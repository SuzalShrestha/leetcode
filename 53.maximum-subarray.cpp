class Solution
{ // Bruteforce approach
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    int sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      int sum1 = 0;
      for (int j = i; j < n; j++)
      {
        sum1 += nums[j];
        sum = max(sum1, sum);
      }
    }
    return sum;
  }
};
class Solution
// Kadane's algorithm
{ // optimal solution
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    int r = 0, l = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      r += nums[i];
      l = max(r, l);
      if (r < 0)
        r = 0;
    }
    return l;
  }
};