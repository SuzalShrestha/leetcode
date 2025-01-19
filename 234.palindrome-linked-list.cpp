class Solution
{ // using stack
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