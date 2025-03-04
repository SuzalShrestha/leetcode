class Solution
{ // backtracking solution
public:
    bool solve(int i, int n, int sum)
    {
        if (sum == n)
            return true;
        if (sum > n || pow(3, i) > n)
            return false;
        if (solve(i + 1, n, sum + pow(3, i)))
            return true;
        return solve(i + 1, n, sum);
    }
    bool checkPowersOfThree(int n) { return solve(0, n, 0); }
};
class Solution
{ // optimal solution
public:
    bool checkPowersOfThree(int n)
    {
        int i = -1;
        while (pow(3, i) <= n)
            i++;
        while (i >= 0)
        {
            int power = pow(3, i);
            if (power <= n)
            {
                n -= power;
            }
            i--;
        }
        if (n == 0)
            return true;
        return false;
        // return n==0
    }
};