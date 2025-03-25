class Solution
{
public:
  int countNonOverlapping(vector<pair<int, int>> &rectangle)
  {
    int cnt = 0;
    int prevEnd = -1;
    for (auto it : rectangle)
    {
      int start = it.first;
      int end = it.second;
      if (start >= prevEnd)
      {
        cnt++;
      }
      prevEnd = max(end, prevEnd);
    }
    return cnt;
  }
  bool checkValidCuts(int n, vector<vector<int>> &rectangles)
  {
    sort(rectangles.begin(), rectangles.end());
    vector<pair<int, int>> x, y;
    for (auto &it : rectangles)
    {
      x.push_back({it[0], it[2]});
      y.push_back({it[1], it[3]});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int xCount = countNonOverlapping(x);
    int yCount = countNonOverlapping(y);
    return max(xCount, yCount) >= 3;
  }
};