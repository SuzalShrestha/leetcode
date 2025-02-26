class Solution
{ // brute solution using set
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    set<ListNode *> s;
    ListNode *temp = headA;
    while (temp)
    {
      s.insert(temp);
      temp = temp->next;
    }
    temp = headB;
    while (temp)
    {
      if (s.find(temp) != s.end())
      {
        return temp;
      }
      temp = temp->next;
    }
    return nullptr;
  }
};
class Solution
{ // brute solution using map
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    map<ListNode *, int> s;
    ListNode *temp = headA;
    while (temp)
    {
      s[temp] = 1;
      temp = temp->next;
    }
    temp = headB;
    while (temp)
    {
      if (s[temp] == 1)
      {
        return temp;
      }
      temp = temp->next;
    }
    return nullptr;
  }
};
class Solution
{ // optimal solution
  // Note:for comparision both iterator should be at same in vertical position. thus we move some d distance forward
  // for larger list
public:
  ListNode *collisionPoint(ListNode *greater, ListNode *smaller,
                           int startpoint)
  {
    while (startpoint)
    {
      startpoint--;
      greater = greater->next;
    }
    while (greater != smaller)
    {
      greater = greater->next;
      smaller = smaller->next;
    }
    return greater;
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    ListNode *temp = headA;
    int c1 = 0, c2 = 0;
    while (temp)
    {
      c1++;
      temp = temp->next;
    }
    temp = headB;
    while (temp)
    {
      c2++;
      temp = temp->next;
    }
    if (c1 > c2)
    {
      return collisionPoint(headA, headB, c1 - c2);
    }
    else
      return collisionPoint(headB, headA, c2 - c1);
  }
};