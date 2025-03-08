class Solution
{ // two pointer approach O(n)
public:
  int minimumRecolors(string blocks, int k)
  {
    int lptr = 0;
    int recolor = 0;
    int res = k;
    int n = blocks.size();
    for (int rptr = 0; rptr < n; rptr++)
    {
      if (blocks[rptr] == 'W')
        recolor++;
      if (rptr - lptr + 1 == k)
      {
        res = min(recolor, res);
        if (blocks[lptr] == 'W')
          recolor--;
        lptr++;
      }
    }
    return res;
  }
};
// we can solve this problem using queue but takes extra space