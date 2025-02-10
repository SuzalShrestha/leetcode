class Solution
{ // bruteforce solution O(n^2)
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int j = 0; j < n; j++)
      {
        if (nums[i] == nums[j])
          cnt++;
      }
      if (cnt > n / 2)
        return nums[i];
    }
    return n;
  }
};
class Solution
{ // better solution
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[nums[i]]++;
    }
    for (auto it : mp)
    {
      if (it.second > (n / 2))
        return it.first;
    }
    return n;
  }
};
class Solution
{ // optimal solution O(NlogN)
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // majority element will always occupy the middle index
    return nums[n / 2];
  }
};
class Solution
// Moore's Voting Algorithm O(n)
{ // optimal solution
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    int cnt = 0;
    int el;
    for (int i = 0; i < n; i++)
    {
      if (cnt == 0)
      {
        cnt = 1;
        el = nums[i];
      }
      else if (nums[i] == el)
        cnt++;
      else
        cnt--;
    }
    // if majority element doesnot always exist
    //  int cnt1 = 0l;
    //  for (int i = 0; i < n; i++)
    //  {
    //    if (nums[i] == el)
    //      cnt1++;
    //  }
    //  if (cn1 > (n / 2))
    //    return el;
    //  return -1;
    return el;
  }
};