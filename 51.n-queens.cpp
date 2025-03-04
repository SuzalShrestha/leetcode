class Solution
{ // brute solution O(n!*n)
public:
  bool isSafe1(int row, int col, vector<string> &board, int n)
  {
    int duprow = row;
    int dupcol = col;
    // check upper diagonal
    while (row >= 0 && col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;
      row--;
      col--;
    }
    row = duprow;
    col = dupcol;
    // check left row
    while (col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;
      col--;
    }
    row = duprow;
    col = dupcol;
    // check lower diagonal
    while (row < n && col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;
      row++;
      col--;
    }
    return true;
  }
  void solve(int col, int n, vector<vector<string>> &ans,
             vector<string> &board)
  {
    if (col == n)
    {
      ans.push_back(board);
      return;
    }
    for (int row = 0; row < n; row++)
    {
      if (isSafe1(row, col, board, n))
      {
        board[row][col] = 'Q';
        solve(col + 1, n, ans, board);
        board[row][col] = '.';
      }
    }
  }
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
      board[i] = s;
    solve(0, n, ans, board);
    return ans;
  }
};
class Solution
{ // optimal solution backtracking with hashing O(n!)
public:
  void solve(int col, int n, vector<vector<string>> &ans,
             vector<string> &board, vector<int> &leftRow,
             vector<int> &upperDiag, vector<int> &lowerDiag)
  {
    if (col == n)
    {
      ans.push_back(board);
      return;
    }
    for (int row = 0; row < n; row++)
    {
      if (leftRow[row] == 0 && upperDiag[n - 1 + col - row] == 0 &&
          lowerDiag[row + col] == 0)
      {
        leftRow[row] = 1;
        upperDiag[n - 1 + col - row] = 1;
        lowerDiag[col + row] = 1;
        board[row][col] = 'Q';
        solve(col + 1, n, ans, board, leftRow, upperDiag, lowerDiag);
        // backtracking
        board[row][col] = '.';
        leftRow[row] = 0;
        upperDiag[n - 1 + col - row] = 0;
        lowerDiag[col + row] = 0;
      }
    }
  }
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans;
    vector<string> board(n);
    // using hashing for O(1) to find is [row][col] is safe or not
    vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0),
        lowerDiag(2 * n - 1, 0);
    string s(n, '.');
    for (int i = 0; i < n; i++)
      board[i] = s;
    solve(0, n, ans, board, leftRow, upperDiag, lowerDiag);
    return ans;
  }
};