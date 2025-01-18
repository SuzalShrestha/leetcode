class Solution // naive solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    if (head == NULL)
      return nullptr;
    ListNode *temp = head;
    ListNode *result = new ListNode(0);
    ListNode *dummynode = result;
    while (temp != NULL)
    {
      result->next = new ListNode(temp->val);
      result = result->next;
      if (temp->next && temp->next->next)
      {
        temp = temp->next->next;
      }
      else
      {
        temp = NULL;
      }
    }
    temp = head->next;
    while (temp != NULL)
    {
      result->next = new ListNode(temp->val);
      result = result->next;
      if (temp->next && temp->next->next)
      {
        temp = temp->next->next;
      }
      else
      {
        temp = NULL;
      }
    }
    return dummynode->next;
  }
};