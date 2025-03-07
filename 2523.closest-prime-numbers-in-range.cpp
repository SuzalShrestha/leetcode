class Solution
{ // optimal solution using Sieve Of Eratosthenes algorithm O(logn(logn))
public:
  vector<int> getsieve(int upperlimit)
  {
    vector<int> sievearr(upperlimit + 1, 1); // assume all are prime
    sievearr[0] = 0;
    sievearr[1] = 0;
    for (int i = 2; i * i <= upperlimit; i++)
    {
      if (sievearr[i] == 1)
      {
        for (int multiple = i * i; multiple <= upperlimit; multiple += i)
        { // mark all multiples
          sievearr[multiple] = 0;
        }
      }
    }
    return sievearr;
  }
  vector<int> closestPrimes(int left, int right)
  {
    vector<int> sieve = getsieve(right);
    vector<int> prime;
    for (int i = left; i <= right; i++)
    { // copy prime numbers
      if (sieve[i] == 1)
        prime.push_back(i);
    }
    if (prime.size() < 2)
      return {-1, -1}; // less than two prime

    int mindiff = INT_MAX;
    vector<int> closestPair(2, -1);
    for (int i = 1; i < prime.size(); i++)
    {
      int diff = prime[i] - prime[i - 1];
      if (diff < mindiff)
      {
        mindiff = diff;
        closestPair[0] = prime[i - 1];
        closestPair[1] = prime[i];
      }
    }
    return closestPair;
  }
};
class Solution
{ // more optimized isPrime function
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
{ // better solution but time exceeded, inefficent isPrime function
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