class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *temp = head;
    stack<int> stack;
    while (temp != NULL)
    {
      stack.push(temp->val);
      temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
      temp->val = stack.top();
      stack.pop();
      temp = temp->next;
    }
    return head;
  }
};
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
      ListNode *front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }
    return prev;
  }
};