class Solution
{ // optimal solution
public:
  long long countInterestingSubarrays(vector<int> &nums, int m, int k)
  {
    int n = nums.size();
    unordered_map<int, long long> mp; // rem->count
    long long sum = 0;
    long long result = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] % m == k)
        sum += 1;
      int r1 = sum % m;
      int r2 = (r1 - k + m) % m;
      result += mp[r2];
      mp[r1]++;
    }
    return result;
  }
};
class Solution
{
public:
  long long countInterestingSubarrays(vector<int> &nums, int m, int k)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (nums[i] % m == k)
      {
        nums[i] = 1;
      }
      else
      {
        nums[i] = 0;
      }
    }
    unordered_map<int, long long> mp; // rem->count
    long long sum = 0;
    long long result = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      int r1 = sum % m;
      int r2 = (r1 - k + m) % m;
      result += mp[r2];
      mp[r1]++;
    }
    return result;
  }
};