class Solution
{
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color)
  {
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> ans = image;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int initial = image[sr][sc];
    ans[sr][sc] = color;
    visited[sr][sc] = 1;
    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      for (auto d : dir)
      {
        int nrow = row + d.first;
        int ncol = col + d.second;
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !visited[nrow][ncol] && image[nrow][ncol] == initial)
        {
          ans[nrow][ncol] = color;
          visited[nrow][ncol] = 1;
          q.push({nrow, ncol});
        }
      }
    }
    return ans;
  }
};