class Solution
{
public:
  int minDepth(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    if (lh == 0)
      return rh + 1;
    if (rh == 0)
      return lh + 1;
    return 1 + min(lh, rh);
  }
};