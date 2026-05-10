class Solution {
public:
  bool helper(vector<vector<char>> &board, string word, int row, int col, vector<vector<bool>> &used, int idx)
{
    if (idx == word.size())
        return true;
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[idx]||used[row][col])
    {
        return false;
    }
    used[row][col] = true;
    bool ans = helper(board, word, row + 1, col, used, idx + 1) || helper(board, word, row - 1, col, used, idx + 1) || helper(board, word, row, col + 1, used, idx + 1) || helper(board, word, row, col - 1, used, idx + 1);
    used[row][col] = false;

    return ans;
}
bool exist(vector<vector<char>> &board, string word)
{
    vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {

        if (helper(board, word, i, j, used, 0))
                return true;
        }
    }
    return false;
}
};
