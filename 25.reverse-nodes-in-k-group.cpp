class Solution
{
public:
  ListNode *reverselist(ListNode *head)
  {
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
      ListNode *next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
    }
    return prev;
  }
  ListNode *findKthNode(ListNode *head, int k)
  {
    k -= 1;
    while (head != NULL)
    {
      if (k == 0)
        return head;
      k--;
      head = head->next;
    }
    return nullptr;
  }
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *temp = head;
    ListNode *nextnode = NULL;
    ListNode *prevnode = NULL;
    while (temp != NULL)
    {
      ListNode *kthnode = findKthNode(temp, k);
      if (kthnode == NULL)
      {
        if (prevnode)
        {
          prevnode->next = temp;
        }
        break;
      }
      nextnode = kthnode->next;
      kthnode->next = NULL;
      reverselist(temp);
      if (temp == head)
        head = kthnode;
      else
        prevnode->next = kthnode;

      prevnode = temp;
      temp = nextnode;
    }
    return head;
  }
};