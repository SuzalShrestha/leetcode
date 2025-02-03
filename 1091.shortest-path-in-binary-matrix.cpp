class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    // its n*n grid
    int n = grid.size();
    // if source and destination doesn't exist
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
      return -1;
    // if only one cell is there
    if (n == 1)
      return 1;
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    dist[0][0] = 0;
    // counted visited cells so 1
    q.push({1, {0, 0}});
    while (!q.empty())
    {
      auto it = q.front();
      q.pop();
      int dis = it.first;
      int row = it.second.first;
      int col = it.second.second;
      // diagonal directions && right, left, down, up
      for (int i = -1; i <= 1; i++)
      {
        for (int j = -1; j <= 1; j++)
        {
          int nrow = row + i;
          int ncol = col + j;
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
              grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol])
          {
            dist[nrow][ncol] = dis + 1;
            if (nrow == n - 1 && ncol == n - 1)
              return dis + 1;
            q.push({dis + 1, {nrow, ncol}});
          }
        }
      }
    }
    return -1;
  }
};