class Solution
{ // using bfs
public:
  vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<pair<int, int>> q;
    for (int i = 0; i < queries.size(); i++)
    {
      q.push_back({queries[i], i});
    }
    sort(q.begin(), q.end());
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>, greater<>>
        minheap;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<int> result(queries.size(), 0);
    minheap.emplace(grid[0][0], make_pair(0, 0));
    visited[0][0] = true;
    int points = 0;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto &[queryVal, queryIndex] : q)
    {
      while (!minheap.empty() && minheap.top().first < queryVal)
      {
        auto [val, pos] = minheap.top();
        minheap.pop();
        int row = pos.first, col = pos.second;
        points++;
        for (auto &[dr, dc] : directions)
        {
          int nr = row + dr, nc = col + dc;
          if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
              !visited[nr][nc])
          {
            minheap.emplace(grid[nr][nc], make_pair(nr, nc));
            visited[nr][nc] = true;
          }
        }
      }
      result[queryIndex] = points;
    }
    return result;
  }
};