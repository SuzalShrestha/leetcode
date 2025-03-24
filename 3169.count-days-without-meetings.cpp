class Solution
{
public:
  int countDays(int days, vector<vector<int>> &meetings)
  {
    sort(meetings.begin(), meetings.end());
    int prevEnd = -1;
    int res = days;
    for (auto &meet : meetings)
    {
      int start = max(prevEnd + 1, meet[0]);
      int end = meet[1];
      int len = end - start + 1;
      if (end >= start)
      {
        res -= len;
        prevEnd = end;
      }
    }
    return res;
  }
};