class Solution // this solution is for 8 directions including diagonal
{
private:
  void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
  {
    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      for (int delrow = -1; delrow <= 1; delrow++)
      {
        for (int delcol = -1; delcol <= 1; delcol++)
        {
          int nrow = row + delrow;
          int ncol = col + delcol;
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1')
          {
            q.push({nrow, ncol});
            visited[nrow][ncol] = 1;
          }
        }
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        if (grid[row][col] == '1' && !visited[row][col])
        {
          cnt++;
          bfs(row, col, visited, grid);
        }
      }
    }
    return cnt;
  }
};
class Solution // solution for 4 directions excluding diagonal
{
private:
  void bfs(int row, int col, vector<vector<int>> &visited,
           vector<vector<char>> &grid)
  {
    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
      for (auto d : dir)
      {
        int nrow = row + d.first;
        int ncol = col + d.second;
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !visited[nrow][ncol] && grid[nrow][ncol] == '1')
        {
          q.push({nrow, ncol});
          visited[nrow][ncol] = 1;
        }
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        if (grid[row][col] == '1' && !visited[row][col])
        {
          cnt++;
          bfs(row, col, visited, grid);
        }
      }
    }
    return cnt;
  }
};