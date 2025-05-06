class Solution
{ // O(1) space
public:
  vector<int> buildArray(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      int old = nums[i];
      int nnew = nums[nums[i]];
      nums[i] = old + n * (nnew % n);
    }
    for (int i = 0; i < n; i++)
    {
      nums[i] = nums[i] / n;
    }
    return nums;
  }
};
class Solution
{
public:
  vector<int> buildArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
      res[i] = nums[nums[i]];
    }
    return res;
  }
};