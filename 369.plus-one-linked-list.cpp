class Solution
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