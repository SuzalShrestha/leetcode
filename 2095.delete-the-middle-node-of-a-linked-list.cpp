class Solution
{ // brute solution
public:
  ListNode *deleteMiddle(ListNode *head)
  {
    if (!head || !head->next)
      return nullptr;
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
      cnt++;
      temp = temp->next;
    }
    int mid = cnt / 2;
    temp = head;
    // traverse right before mid node
    for (int i = 0; i < mid - 1; i++)
      temp = temp->next;
    ListNode *middlenode = temp->next;
    temp->next = temp->next->next;
    delete middlenode;
    return head;
  }
};
class Solution
{ // optimal solution with not great exception handling
public:
  ListNode *deleteMiddle(ListNode *head)
  {
    if (!head || !head->next)
      return nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (slow->next != NULL)
    {
      ListNode *temp = slow->next;
      slow->val = temp->val;
      slow->next = temp->next;
    }
    else
    {
      head->next = nullptr;
    }
    return head;
  }
};
class Solution
{ // optimal solution with prev pointer
public:
  ListNode *deleteMiddle(ListNode *head)
  {
    if (!head || !head->next)
      return nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast && fast->next)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
  }
};
class Solution
{ // optimal solution with better exception handling
public:
  ListNode *deleteMiddle(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
    {
      return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    // exception handling for 2 node linkedlist
    fast = head->next->next;
    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};