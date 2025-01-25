class Solution
{
public:
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    if (root == NULL)
      return new TreeNode(val);
    TreeNode *cur = root;
    while (true)
    {
      if (val > cur->val)
      {
        if (cur->right)
          cur = cur->right;
        else
        {
          cur->right = new TreeNode(val);
          break;
        }
      }
      else
      {
        if (cur->left)
          cur = cur->left;
        else
        {
          cur->left = new TreeNode(val);
          break;
        }
      }
    }
    return root;
  }
};