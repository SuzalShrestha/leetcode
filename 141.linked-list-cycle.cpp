class Solution
{ // bruteforce solution using hashing with set
public:
  bool hasCycle(ListNode *head)
  {
    ListNode *temp = head;
    unordered_set<ListNode *> s;
    while (temp)
    {
      if (s.find(temp) != s.end())
        return true;
      s.insert(temp);
      temp = temp->next;
    }
    return false;
  }
};
class Solution
{ // optimal solution using toroise and hare
public:
  bool hasCycle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
        return true;
    }
    return false;
  }
};