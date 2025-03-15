class Solution
{ // using dynamic programming
public:
  int rob(vector<int> &nums)
  {
    int rob1 = 0, rob2 = 0;
    for (int it : nums)
    {
      int temp = max(it + rob1, rob2);
      rob1 = rob2;
      rob2 = temp;
    }
    return rob2;
  }
};