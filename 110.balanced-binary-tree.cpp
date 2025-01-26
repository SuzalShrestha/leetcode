class Solution
{
public:
  int check(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    int lh = check(root->left);
    int rh = check(root->right);
    if (lh == -1 || rh == -1)
      return -1;
    if (abs(lh - rh) > 1)
      return -1;
    return max(lh, rh) + 1;
  }
  bool isBalanced(TreeNode *root)
  {
    if (check(root) != -1)
      return true;
    return false;
  }
};