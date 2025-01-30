class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    vector<vector<int>> rotten = grid;
    queue<pair<pair<int, int>, int>> q;
    int cntfresh = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({{i, j}, 0});
          visited[i][j] = 2;
        }
        if (grid[i][j] == 1)
          cntfresh++;
      }
    }
    int tm = 0;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int t = q.front().second;
      tm = max(tm, t);
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
        {
          rotten[nrow][ncol] = 2;
          q.push({{nrow, ncol}, t + 1});
          visited[nrow][ncol] = 2;
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (rotten[i][j] == 1 && visited[i][j] != 2)
          return -1;
      }
    }
    return tm;
  }
};