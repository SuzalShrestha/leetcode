class Solution
{ // more optimized is prime
public:
  bool isPrime(int x)
  {
    if (x <= 1)
      return false;
    if (x == 2 || x == 3)
      return true;
    // we check for multiple for 2 and 3
    if (x % 2 == 0 || x % 3 == 0)
      return false;
    // we check for price numbers 6k-1 type as all prime number follows it
    for (int i = 5; i * i <= x; i += 6)
    {
      if (x % i == 0 || x % (i + 2) == 0)
        return false;
    }
    return true;
  }
  vector<int> closestPrimes(int left, int right)
  {
    int prev = -1, num1 = -1, num2 = -1;
    int mindiff = INT_MAX;
    for (int i = left; i <= right; i++)
    {
      if (isPrime(i))
      {
        // keep track of prev and minimum diff
        if (prev != -1 && (i - prev) < mindiff)
        {
          mindiff = i - prev;
          num1 = prev;
          num2 = i;
        }
        prev = i;
      }
    }
    return {num1, num2};
  }
};
class Solution
{ // correct but time exceeded, inefficent isprime
public:
  bool isPrime(int x)
  {
    if (x <= 1)
      return false;
    if (x == 2 || x == 3)
      return true;
    if (x % 2 == 0 || x % 3 == 0)
      return false;
    int cnt = 0;
    for (int i = 5; i * i <= x; i++)
    {
      if (x % i == 0)
        cnt++;
    }
    return cnt == 0;
  }
  vector<int> closestPrimes(int left, int right)
  {
    int prev = -1, num1 = -1, num2 = -1;
    int mindiff = INT_MAX;
    for (int i = left; i <= right; i++)
    {
      if (isPrime(i))
      {
        if (prev != -1 && (i - prev) < mindiff)
        {
          mindiff = i - prev;
          num1 = prev;
          num2 = i;
        }
        prev = i;
      }
    }
    return {num1, num2};
  }
};