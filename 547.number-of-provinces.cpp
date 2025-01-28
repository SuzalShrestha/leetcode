class Solution
{
public:
  void dfs(int node, vector<int> &visited, vector<vector<int>> &isConnected, int V)
  {
    visited[node] = 1;
    for (int i = 0; i < V; i++)
    {
      if (!visited[i] && isConnected[node][i] == 1)
      {
        dfs(i, visited, isConnected, V);
      }
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int V = isConnected.size();
    vector<int> visited(V, 0);
    int province = 0;
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        dfs(i, visited, isConnected, V);
        province++;
      }
    }
    return province;
  }
};