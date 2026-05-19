class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }

        vector<vector<int>> res;
        vector<int> prevRow = {1};
        res.push_back(prevRow);
        for (int row = 2; row <= numRows; row++) {
            vector<int> currentRow;
            currentRow.push_back(1);
            for (int i = 1; i < prevRow.size(); i++) {
                int val = prevRow[i - 1] + prevRow[i];
                currentRow.push_back(val);
            }
            currentRow.push_back(1);
            prevRow = currentRow;
            res.push_back(currentRow);
        }

        return res;
    }
};