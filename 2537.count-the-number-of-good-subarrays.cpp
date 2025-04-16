class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        map<int, int> mp;
        long long result = 0;
        long long pairs = 0;
        while (j < n)
        {
            pairs += mp[nums[j]];
            mp[nums[j]]++;
            while (pairs >= k)
            {
                result += (n - j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }
        return result;
    }
};