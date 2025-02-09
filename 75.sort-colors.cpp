class Solution
{
public:
  int pivot(vector<int> &arr, int low, int high)
  {
    int pivotele = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
      while (i < high && arr[i] <= pivotele)
        i++;
      while (j > low && arr[j] > pivotele)
        j--;
      if (i < j)
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
  }
  void quicksort(vector<int> &arr, int low, int high)
  {
    if (low < high)
    {
      int pivotele = pivot(arr, low, high);
      quicksort(arr, low, pivotele - 1);
      quicksort(arr, pivotele + 1, high);
    }
  }
  void sortColors(vector<int> &nums)
  {
    return quicksort(nums, 0, nums.size() - 1);
  }
};
class Solution
{ // bruteforce solution as nums contain 0,1 and 2 only.
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();
    int zeros = 0, ones = 0, twos = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
        zeros++;
      if (nums[i] == 1)
        ones++;
      else
        twos++;
    }
    for (int i = 0; i < zeros; i++)
    {
      nums[i] = 0;
    }
    for (int i = zeros; i < zeros + ones; i++)
    {
      nums[i] = 1;
    }
    for (int i = zeros + ones; i < n; i++)
    {
      nums[i] = 2;
    }
  }
};
class Solution
{ // Dutch National Flag algorithm ->O(n)
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
      if (nums[mid] == 0)
      {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
      }
      else if (nums[mid] == 1)
        mid++;
      else
      {
        swap(nums[high], nums[mid]);
        high--;
      }
    }
  }
};