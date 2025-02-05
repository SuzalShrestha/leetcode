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
// using disjointset
class DisjointSet
{
public:
  vector<int> rank, parent, size;
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;
  }
  int findUltimateParent(int node) // retrieve at constant time
  {
    if (node == parent[node])
      return node;
    return parent[node] = findUltimateParent(parent[node]);
  }
  void unionBySize(int u, int v)
  {
    int ulp_u = findUltimateParent(u);
    int ulp_v = findUltimateParent(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};
class Solution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    DisjointSet ds(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (isConnected[i][j] == 1)
        {
          ds.unionBySize(i, j);
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (ds.findUltimateParent(i) == i)
        cnt++;
    }
    return cnt;
  }
};