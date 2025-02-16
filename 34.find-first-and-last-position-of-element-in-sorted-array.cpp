class Solution
{ // optimal solution O(logn)
    // using upper and lower bound
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> res(2, -1);
        int high = n - 1, low = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // lower bound
            if (nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (low < n && nums[low] == target)
            res[0] = low;
        low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // upper bound
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (high >= 0 && nums[high] == target)
            res[1] = high;
        return res;
    }
};
class Solution
{ // bruteforce solution O(n)
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> res(2, -1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                if (res[0] == -1)
                    res[0] = i;
                res[1] = i;
            }
        }
        return res;
    }
};