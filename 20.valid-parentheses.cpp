#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> stack;

    for (char bracket : s)
    {
      if (bracket == '(' || bracket == '{' || bracket == '[')
      {
        stack.push(bracket);
      }
      else
      {
        if (stack.empty())
          return false;

        char top = stack.top();
        if ((bracket == ')' && top != '(') ||
            (bracket == '}' && top != '{') ||
            (bracket == ']' && top != '['))
        {
          return false;
        }
        stack.pop();
      }
    }
    return stack.empty();
  }
};