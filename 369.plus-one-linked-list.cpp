class Solution // iterative solution
// T.C->O(3n)
// S.C->O(1)
{
public:
  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = NULL;
    ListNode *temp = head;
    ListNode *front = NULL;
    while (temp != NULL)
    {
      front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }
    return prev;
  }
  ListNode *addOne(ListNode *head)
  {
    head = reverse(head);
    ListNode *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
      int data = temp->data;
      temp->data = (carry + data) % 10;
      carry = (carry + data) / 10;
      temp = temp->next;
    }
    if (carry)
    {
      ListNode *newhead = new ListNode(carry);
      newhead->next = reverse(head);
      return newhead;
    }
    return reverse(head);
  }
};
class Solution // optimal recursive solution
// T.C->O(n)
// S.C->O(n)
{
public:
  int recursive(ListNode *temp)
  {
    if (temp == NULL)
    {
      return 1;
    }
    int carry = recursive(temp->next);
    int data = temp->data;
    temp->data = (carry + data) % 10;
    return (carry + data) / 10;
  }
  ListNode *addOne(ListNode *head)
  {
    int carry = recursive(head);
    if (carry == 1)
    {
      ListNode *newhead = new ListNode(carry);
      newhead->next = head;
      return newhead;
    }
    return head;
  }
};