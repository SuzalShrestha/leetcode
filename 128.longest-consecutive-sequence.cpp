class Solution
{ // naive bruteforce solution O(n^2)
public:
  bool ls(vector<int> &nums, int x)
  {
    for (auto it : nums)
    {
      if (x == it)
        return true;
    }
    return false;
  }
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
      int x = nums[i];
      int cnt = 1;
      while (ls(nums, x + 1) == true)
      {
        x++;
        cnt++;
      }
      longest = max(cnt, longest);
    }
    return longest;
  }
};
class Solution
{ // better solution O(nlogn)
public:
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    int n = nums.size();
    int maxl = 0;
    int cnt = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++)
    {
      int diff = nums[i + 1] - nums[i];
      if (diff == 0)
        continue;
      if (diff == 1)
        cnt++;
      else
      {
        maxl = max(maxl, cnt);
        cnt = 1;
      }
    }
    return max(maxl, cnt);
  }
};
class Solution
{ // better better solution in leetcode in runtime and space
public:
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int longest = 1;
    int cnt = 0;
    int lastsmaller = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      int curr = nums[i];
      if (curr - 1 == lastsmaller)
      {
        cnt++;
        lastsmaller = curr;
      }
      else if (curr != lastsmaller)
      {
        cnt = 1;
        lastsmaller = curr;
      }
      longest = max(longest, cnt);
    }
    return longest;
  }
};
class Solution
{ // optimal solution O(n)
public:
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();
    int maxl = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
      s.insert(nums[i]);
    }
    for (auto it : s)
    {
      if (s.find(it - 1) == s.end()) // O(1) lookup
      {
        int currnum = it;
        int cnt = 1;
        while (s.find(currnum + 1) != s.end())
        {
          currnum += 1;
          cnt++;
        }
        maxl = max(maxl, cnt);
      }
    }
    return maxl;
  }
};