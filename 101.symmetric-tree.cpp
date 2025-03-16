class Solution
{
public:
  bool isSym(TreeNode *root1, TreeNode *root2)
  {
    if (!root1 && !root2)
      return true;
    if (!root1 || !root2)
      return false;
    if (root1->val != root2->val)
      return false;
    return isSym(root1->right, root2->left) &&
           isSym(root2->right, root1->left);
  }
  bool isSymmetric(TreeNode *root) { return isSym(root, root); }
};