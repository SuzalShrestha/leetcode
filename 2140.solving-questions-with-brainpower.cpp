class Solution
{
public:
  long long back(long long i, vector<vector<int>> &questions,
                 vector<long long> &dp)
  {
    if (i >= questions.size())
      return 0;
    if (dp[i])
      return dp[i];
    int points = questions[i][0];
    int brainpower = questions[i][1];
    dp[i] = max(back(i + 1, questions, dp), // skip
                points + back(i + brainpower + 1, questions, dp));
    return dp[i];
  }
  long long mostPoints(vector<vector<int>> &questions)
  {
    vector<long long> dp(questions.size(), 0);
    return back(0, questions, dp);
  }
};