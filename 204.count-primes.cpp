class Solution
{ // using sieve of eratosthenes algorithm
public:
  int countPrimes(int n)
  {
    if (n <= 2)
      return 0;
    int ans = 0;
    vector<int> sieve(n, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i * i < n; i++)
    {
      if (sieve[i] == 1)
      {
        for (int multiple = i * i; multiple < n; multiple += i)
          sieve[multiple] = 0;
      }
    }
    return count(sieve.begin(), sieve.end(), 1);
  }
};