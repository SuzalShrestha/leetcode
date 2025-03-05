class Solution
{ // using backtracking
public:
  bool isValid(char c, vector<vector<char>> &board, int row, int col)
  {
    for (int i = 0; i < 9; i++)
    {
      if (board[i][col] == c)
        return false;
      if (board[row][i] == c)
        return false;
      if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        return false;
    }
    return true;
  }
  bool solve(vector<vector<char>> &board)
  {
    for (int row = 0; row < board[0].size(); row++)
    {
      for (int col = 0; col < board.size(); col++)
      {
        if (board[row][col] == '.')
        {
          for (char c = '1'; c <= '9'; c++)
          {
            if (isValid(c, board, row, col))
            {
              board[row][col] = c;
              if (solve(board) == true)
                return true;
              else
                board[row][col] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  void solveSudoku(vector<vector<char>> &board) { solve(board); }
};