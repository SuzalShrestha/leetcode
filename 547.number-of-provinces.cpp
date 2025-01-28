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
// Note: You can change adjacency matrix into adjacency list using loops and then perform the algorithm if necessary
// for (int i = 0; i < N; i++)
// {
//   for (int j = 0; j < N; j++)
//   {
//     if (isConnected[i][j] == 1 && i != j)
//     {
//       adj[i].push_back(j);
//       adj[j].push_back(i);
//     }
//   }
// }