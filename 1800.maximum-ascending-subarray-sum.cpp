class Solution
{ // optimal solution
public:
  int maxAscendingSum(vector<int> &nums)
  {
    int n = nums.size();
    int maxsum = 0;
    int currentsum = nums[0];
    for (int i = 1; i < n; i++)
    {
      if (nums[i] <= nums[i - 1])
      {
        maxsum = max(maxsum, currentsum);
        currentsum = 0;
      }
      currentsum += nums[i];
    }
    return max(maxsum, currentsum);
  }
};
class Solution
{ // Bruteforce solution
public:
  int maxAscendingSum(vector<int> &nums)
  {
    int maxSum = 0;

    // Outer loop to start from each element in the array
    for (int i = 0; i < nums.size(); i++)
    {
      int currentSubarraySum = nums[i];
      // Inner loop to check the next elements forming an ascending
      // subarray
      for (int j = i + 1;
           j < nums.size() && nums[j] > nums[j - 1];
           j++)
      {
        currentSubarraySum += nums[j];
      }
      // Update maxSum if we find a larger ascending subarray sum
      maxSum = max(maxSum, currentSubarraySum);
    }

    return maxSum;
  }
};