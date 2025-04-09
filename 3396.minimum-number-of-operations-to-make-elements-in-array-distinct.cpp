class Solution
{
public:
    bool checkDistinct(int idx, vector<int> &nums)
    {
        unordered_set<int> st;
        for (int i = idx; i < nums.size(); i++)
        {
            if (st.find(nums[i]) != st.end())
            {
                return false;
            }
            st.insert(nums[i]);
        }
        return true;
    }
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        int op = 0;
        for (int i = 0; i < n; i += 3)
        {
            if (checkDistinct(i, nums) == true)
            {
                return op;
            }
            op++;
        }
        return op;
    }
};