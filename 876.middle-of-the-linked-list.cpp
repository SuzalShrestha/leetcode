class Solution
{ // optimal solution -> tortoise hare problem
public:
  ListNode *middleNode(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};
class Solution
{ // bruteforce solution
public:
  ListNode *middleNode(ListNode *head)
  {
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
      cnt++;
      temp = temp->next;
    }
    int midnode = cnt / 2 + 1;
    temp = head;
    while (temp != NULL)
    {
      midnode--;
      if (midnode == 0)
        break;
      temp = temp->next;
    }
    return temp;
  }
};