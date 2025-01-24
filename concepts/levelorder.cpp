#include <iostream>
using namespace std;
struct Node
{
  int data;
  struct Node *left, *right;
  Node(int x)
  {
    data = x;
    left = right = nullptr;
  }
};
vector<vector<int> > levelorder(struct Node *node)
{
  vector<vector<int> > ans;
  if (node == NULL)
    return ans;
  queue<Node *> q;
  q.push(node);
  while (!q.empty())
  {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++)
    {
      Node *node = q.front();
      q.pop();
      if (node->left != NULL)
        q.push(node->left);
      if (node->right != NULL)
        q.push(node->right);
      level.push_back(node->data);
    }
    ans.push_back(level);
  }
  return ans;
}
int main()
{
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  root->right->left = new Node(7);
  cout << "Levelorder traversal of binary tree is: \n";
  vector<vector<int> > ans = levelorder(root);
  for (int i = 0; i < 3; i++)
  {
    vector<int> node = ans[i];
    for (int j = 0; j < node.size(); j++)
    {
      cout << node[j];
    }
    cout << endl;
  }
  return 0;
}