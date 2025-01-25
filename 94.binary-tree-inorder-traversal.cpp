class Solution
{
public:
  void helper(TreeNode *root, vector<int> &result)
  {
    if (root == NULL)
      return;
    helper(root->left, result);
    result.push_back(root->val);
    helper(root->right, result);
  }
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> result;
    helper(root, result);
    return result;
  }
};