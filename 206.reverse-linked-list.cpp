class Solution // stack approach and uses two traversal
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
class Solution // reverses list at one traversal at constant space complexity
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
class Solution // recursive solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
    {
      return head;
    }
    ListNode *newhead = reverseList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
  }
};