/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
// TC->O(length)+O(length-n)-->max is 0(2*length)
// SC->O(1)
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *temp = head;
    ListNode *curr = head;
    int count = 1;
    while (curr->next)
    {
      count++;
      curr = curr->next;
    }
    if (count == n)
    {
      head = head->next;
      return head;
    }
    for (int i = 1; i < count - n && temp; i++)
    {
      temp = temp->next;
    }
    if (temp->next->next)
    {
      ListNode *deletenode = temp->next;
      temp->next = temp->next->next;
      delete deletenode;
    }
    else if (temp->next)
    {
      temp->next = NULL;
      return head;
    }
    return head;
  }
};
class SpaceOptimalSolution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *curr = head;
    int count = 0;
    while (curr != NULL)
    {
      count++;
      curr = curr->next;
    }
    if (count == n)
    {
      ListNode *newhead = head->next;
      delete head;
      return newhead;
    }
    int res = count - n;
    curr = head;
    while (curr != NULL)
    {
      res--;
      if (res == 0)
        break;
      curr = curr->next;
    }
    ListNode *deletenode = curr->next;
    curr->next = curr->next->next;
    delete deletenode;
    return head;
  }
};
class TimeOptimalSolution
// optimal approach using fast and slow two pointers inorder to get the
// required position without knowing the length.
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *fast = head;
    ListNode *slow = head;
    for (int i = 0; i < n; i++)
    {
      fast = fast->next;
      if (fast == NULL)
      {
        ListNode *newhead = head->next;
        delete head;
        return newhead;
      }
    }
    while (fast->next != NULL)
    {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *delnode = slow->next;
    slow->next = slow->next->next;
    delete delnode;
    return head;
  }
};