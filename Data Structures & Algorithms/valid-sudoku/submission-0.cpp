class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
    // Create a vector of sets for rows, columns, and sub-boxes
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);
    
    // Traverse the 9x9 board
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num == '.') continue;  // Skip empty cells
            
            // Check if the number exists in the row
            if (rows[i].count(num)) return false;
            rows[i].insert(num);
            
            // Check if the number exists in the column
            if (cols[j].count(num)) return false;
            cols[j].insert(num);
            
            // Check if the number exists in the 3x3 sub-box
            int boxIndex = (i / 3) * 3 + (j / 3);
            if (boxes[boxIndex].count(num)) return false;
            boxes[boxIndex].insert(num);
        }
    }
    
    return true;  // No duplicates found, board is valid
}
};
