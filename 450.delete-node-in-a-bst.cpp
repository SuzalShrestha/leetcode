class Solution
{
public:
  TreeNode *helper(TreeNode *root)
  {
    if (root->left == NULL)
      return root->right;
    else if (root->right == NULL)
      return root->left;
    TreeNode *curr = root;
    TreeNode *rightchild = root->right;
    TreeNode *lastright = findrightmost(root->left);
    lastright->right = rightchild;
    return root->left;
  }
  TreeNode *findrightmost(TreeNode *root)
  {
    if (root->right == NULL)
      return root;
    return findrightmost(root->right);
  }
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return root;
    if (root->val == key)
    {
      return helper(root);
    }
    TreeNode *curr = root;
    while (curr != NULL)
    {
      if (curr->val > key)
      {
        if (curr->left != NULL && curr->left->val == key)
        {
          curr->left = helper(curr->left);
          break;
        }
        else
        {
          curr = curr->left;
        }
      }
      else
      {
        if (curr->right != NULL && curr->right->val == key)
        {
          curr->right = helper(curr->right);
          break;
        }
        else
        {
          curr = curr->right;
        }
      }
    }
    return root;
  }
};