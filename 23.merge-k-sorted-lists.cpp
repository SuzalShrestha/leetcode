bool comp(int a, int b)
{
  return a < b;
}
class Solution // using array and sort
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    vector<int> curr;
    ListNode *dummynode = new ListNode(0);
    ListNode *result = dummynode;
    for (ListNode *node : lists)
    {
      while (node != NULL)
      {
        curr.push_back(node->val);
        node = node->next;
      }
    }
    sort(curr.begin(), curr.end(), comp);
    for (int val : curr)
    {
      result->next = new ListNode(val);
      result = result->next;
    }
    return dummynode->next;
  }
};