class Solution
{ // bruteforce solution
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size();
    int zcnt = 0;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
        zcnt++;
      else
        res.push_back(nums[i]);
    }
    for (int i = 1; i <= zcnt; i++)
      res.push_back(0);
    nums = res;
  }
};
class Solution
{ // better bruteforce solution
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] != 0)
        res.push_back(nums[i]);
    }
    for (int i = 0; i < res.size(); i++)
    {
      nums[i] = res[i];
    }
    for (int i = 0; i < n - res.size(); i++)
    {
      nums[res.size() + i] = 0;
    }
  }
};
class Solution
{ // Optimal Solution SC->O(1)
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 1)
      return;
    int zp = -1;
    int ip = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
      {
        zp = i;
        break;
      }
    }
    if (zp == -1)
      return;
    for (int i = zp + 1; i < n; i++)
    {
      if (nums[i] != 0)
      {
        swap(nums[zp], nums[i]);
        zp++;
      }
    }
  }
};