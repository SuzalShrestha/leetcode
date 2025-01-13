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
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *dummynode = new ListNode(0);
    ListNode *curr = dummynode;
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
      int sum = carry;
      if (l1)
      {
        sum = sum + l1->val;
      }
      if (l2)
      {
        sum = sum + l2->val;
      }
      curr->next = new ListNode(sum % 10);
      carry = sum / 10;
      curr = curr->next;
      if (l1)
      {
        l1 = l1->next;
      }
      if (l2)
      {
        l2 = l2->next;
      }
    }
    if (carry)
    {
      curr->next = new ListNode(carry);
    }
    return dummynode->next;
  }
};