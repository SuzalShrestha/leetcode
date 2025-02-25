class Solution
{ // brute solution
public:
  ListNode *sortList(ListNode *head)
  {
    vector<int> arr;
    ListNode *temp = head;
    while (temp)
    {
      arr.push_back(temp->val);
      temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    for (auto it : arr)
    {
      temp->val = it;
      temp = temp->next;
    }
    return head;
  }
};
class Solution
{ // optimal solution using merge sort
public:
  ListNode *findmid(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  ListNode *merge(ListNode *lefthead, ListNode *righthead)
  {
    ListNode *dummynode = new ListNode(-1);
    ListNode *temp = dummynode;
    while (lefthead != NULL && righthead != NULL)
    {
      if (lefthead->val < righthead->val)
      {
        temp->next = lefthead;
        temp = lefthead;
        lefthead = lefthead->next;
      }
      else
      {
        temp->next = righthead;
        temp = righthead;
        righthead = righthead->next;
      }
    }
    if (lefthead)
      temp->next = lefthead;
    else
      temp->next = righthead;
    return dummynode->next;
  }
  ListNode *sortList(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *middle = findmid(head);
    ListNode *lefthead = head;
    ListNode *righthead = middle->next;
    middle->next = NULL;
    lefthead = sortList(lefthead);
    righthead = sortList(righthead);
    return merge(lefthead, righthead);
  }
};