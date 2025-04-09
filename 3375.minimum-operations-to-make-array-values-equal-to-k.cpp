class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_set<int> st;
        for (int &it : nums)
        {
            if (it < k)
                return -1;
            else if (it > k)
            {
                st.insert(it);
            }
        }
        return st.size();
    }
};