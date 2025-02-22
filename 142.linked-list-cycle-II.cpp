class Solution
{ // brute solution
public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *temp = head;
    unordered_set<ListNode *> s;
    while (temp != NULL)
    {
      if (s.find(temp) != s.end())
        return temp;
      s.insert(temp);
      temp = temp->next;
    }
    return nullptr;
  }
};
class Solution
{ // optimal solution using Floyd’s Cycle Detection Algorithm
public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
      {
        slow = head;
        while (slow != fast)
        {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};