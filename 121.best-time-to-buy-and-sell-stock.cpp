class Solution
{ // optimal solution
public:
  int maxProfit(vector<int> &prices)
  {
    int minprice = prices[0];
    int n = prices.size();
    int maxprofit = 0;
    for (int i = 1; i < n; i++)
    {
      minprice = min(minprice, prices[i]);
      maxprofit = max(maxprofit, prices[i] - minprice);
    }
    return maxprofit;
  }
};