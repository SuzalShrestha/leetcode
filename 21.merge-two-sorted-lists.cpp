class Solution
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
};