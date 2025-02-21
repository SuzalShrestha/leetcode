class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
class Solution
{ // memory leak optimized
public:
  void deleteNode(ListNode *node)
  {
    ListNode *temp = node->next;
    // copy next node into current node
    node->val = temp->val;
    node->next = temp->next;
    // delete the next node
    delete temp;
  }
};