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
class Solution
{ // TC->O(n) SC->O(1)
public:
  ListNode *oddEvenList(ListNode *head)
  {
    if (!head)
      return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenhead = head->next;
    while (odd->next && even->next)
    {
      odd->next = even->next;
      even->next = odd->next->next;
      odd = odd->next;
      even = even->next;
    }
    odd->next = evenhead;
    return head;
  }
};