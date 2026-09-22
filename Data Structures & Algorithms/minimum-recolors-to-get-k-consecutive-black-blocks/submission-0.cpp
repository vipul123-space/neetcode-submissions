class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int start = 0;
        int end = k;
        int countW = 0;

        for (int i = 0; i < end; i++) {
            if (blocks[i] == 'W') {
                countW++;
            }
        }

        int res = countW;
        while (end < blocks.size()) {

            if (blocks[end] == 'W') {
                countW++;
            }
            if (blocks[start] == 'W') {
                countW--;
            }
            res = min(res, countW);
            start++;
            end++;
        }

        return res;
    }
};