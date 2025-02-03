class Solution
{
public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                   pair<int, int> destination)
  {
    // if source and destination are same
    if (source.first == destination.first && source.second == destination.second)
      return 0;
    // we donot need pq here as all the edges have same weight
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});
    // right, left, down, up
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty())
    {
      auto it = q.front();
      q.pop();
      int dis = it.first;
      int row = it.second.first;
      int col = it.second.second;
      for (auto d : dir)
      {
        int nrow = row + d[0];
        int ncol = col + d[1];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol])
        {
          dist[nrow][ncol] = dis + 1;
          if (nrow == destination.first && ncol == destination.second)
            return dis + 1;
          q.push({dis + 1, {nrow, ncol}});
        }
      }
    }
    // if destination is not reachable
    return -1;
  }
};