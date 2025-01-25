int findCeil(Node *root, int val)
{
  int ceil = -1;
  while (root)
  {
    if (root->val == val)
    {
      return val;
    }
    if (val > root->val)
    {
      root = root->right;
    }
    else
    {
      ceil = root->val;
      root = root->left;
    }
  }
  return ceil;
};
int findfloor(Node *root, int val)
{
  int floor = -1;
  while (root)
  {
    if (val == root->val)
    {
      return val;
    }
    if (val > root->val)
    {
      floor = root->val;
      root = root->right;
    }
    else
    {
      root = root->left;
    }
  }
  return floor;
};