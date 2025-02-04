// union by rank
#include <iostream>
using namespace std;
class DisjointSet
{
  vector<int> rank, parent;

public:
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;
  }
  int findUlimateParent(int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = findUlimateParent(parent[node]);
  }
  void unionByRank(int u, int v)
  {
    int ulp_u = findUlimateParent(u);
    int ulp_v = findUlimateParent(v);
    if (ulp_u == ulp_v)
      return;
    if (rank[ulp_u] > rank[ulp_v])
    {
      parent[ulp_v] = ulp_u;
    }
    else if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else
    {
      parent[ulp_u] = ulp_v;
      rank[ulp_u]++;
    }
  }
};
int main()
{
  DisjointSet ds(7);
  ds.unionByRank(1, 2);
  ds.unionByRank(2, 3);
  ds.unionByRank(4, 5);
  ds.unionByRank(6, 7);
  ds.unionByRank(5, 6);
  if (ds.findUlimateParent(3) == ds.findUlimateParent(7))
  {
    cout << "Same\n";
  }
  else
    cout << "Not Same\n";
  ds.unionByRank(3, 7);
  if (ds.findUlimateParent(3) == ds.findUlimateParent(7))
  {
    cout << "Same\n";
  }
  else
    cout << "Not Same\n";
  return 0;
}