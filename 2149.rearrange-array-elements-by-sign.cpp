class Solution
{ // bruteforce solution
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    for (auto it : nums)
    {
      if (it >= 0)
        pos.push_back(it);
      else
        neg.push_back(it);
    }
    for (int i = 0; i < n / 2; i++)
    {
      nums[i * 2] = pos[i];
      nums[i * 2 + 1] = neg[i];
    }
    return nums;
  }
};
class Solution
{ // optimal solution as we need extra space
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans(n);
    int pos = 0;
    int neg = 1;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] >= 0)
      {
        ans[pos] = nums[i];
        pos += 2;
      }
      else
      {
        ans[neg] = nums[i];
        neg += 2;
      }
    }
    return ans;
  }
};