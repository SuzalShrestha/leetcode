class Solution
{ // using stack S.C->O(n)
public:
  bool isPalindrome(ListNode *head)
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
      if (temp->val != stack.top())
      {
        return false;
      }
      stack.pop();
      temp = temp->next;
    }
    return true;
  }
};
class Solution // S.C->O(1) optimal approach
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
  bool isPalindrome(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *newhead = reverse(slow->next);
    ListNode *first = head;
    ListNode *second = newhead;
    while (second != NULL)
    {
      if (first->val != second->val)
      {
        reverse(newhead);
        return false;
      }
      first = first->next;
      second = second->next;
    }
    reverse(newhead);
    return true;
  }
};