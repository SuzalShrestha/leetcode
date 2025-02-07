class Solution
{ // Bruteforce solution O(n^2)
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k = k % n;
    for (int i = 0; i < k; i++)
    {
      int temp = nums[n - 1];
      for (int j = n - 1; j > 0; --j)
      {
        nums[j] = nums[j - 1];
      }
      nums[0] = temp;
    }
  }
};
class Solution
{ // better solution O(n)
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k = k % n;
    vector<int> temp(n);
    for (int i = 0; i < k; i++)
    {
      temp[i] = nums[n - k + i];
    }
    for (int i = 0; i < n - k; i++)
    {
      temp[k + i] = nums[i];
    }
    for (int i = 0; i < n; i++)
    {
      nums[i] = temp[i];
    }
  }
};