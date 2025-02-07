class Solution
{ // two pointer approach
public:
  int removeDuplicates(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    int n = nums.size();
    int k = 1;
    for (int i = 1; i < n; i++)
    {
      if (nums[i] != nums[i - 1])
      {
        nums[k] = nums[i];
        k++;
      }
    }
    return k;
  }
};
class Solution
{ // bruteforce solution
public:
  int removeDuplicates(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    int n = nums.size();
    set<int> s;
    int k = 0;
    for (int i = 0; i < n; i++)
      s.insert(nums[i]);
    for (auto it : s)
    {
      nums[k] = it;
      k++;
    }
    return k;
  }
};