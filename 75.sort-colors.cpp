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