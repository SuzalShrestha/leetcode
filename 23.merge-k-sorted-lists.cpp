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
class Solution // using mergetwolists apporach but it is not optimal for time complexity but is optimal for space complexity
{
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *result = new ListNode(0);
    ListNode *dummyhead = result;
    while (list1 != NULL && list2 != NULL)
    {
      if (list2->val >= list1->val)
      {
        result->next = list1;
        list1 = list1->next;
      }
      else
      {
        result->next = list2;
        list2 = list2->next;
      }
      result = result->next;
    }
    if (list1 != NULL)
    {
      result->next = list1;
    }
    else if (list2 != NULL)
    {
      result->next = list2;
    }
    return dummyhead->next;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (lists.empty())
      return nullptr;
    ListNode *head = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
      head = mergeTwoLists(head, lists[i]);
    }
    return head;
  }
};