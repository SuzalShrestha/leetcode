class Solution
{ // hashing using array O(n^2)
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
  {
    vector<int> h(grid.size() * grid.size() + 1, 0);
    int doub = 0, miss = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        h[grid[i][j]] += 1;
      }
    }
    for (int i = 1; i < h.size(); i++)
    {
      if (h[i] == 2)
        doub = i;
      if (h[i] == 0)
        miss = i;
    }
    return {doub, miss};
  }
};
class Solution
{ // using unordered map
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int missing = -1, repeat = -1;
    unordered_map<int, int> freq;
    for (auto &row : grid)
    {
      for (int num : row)
      {
        freq[num]++;
      }
    }
    for (int i = 1; i <= n * n; i++)
    {
      if (!freq.count(i))
        missing = i;
      else if (freq[i] == 2)
        repeat = i;
    }
    return {repeat, missing};
  }
};