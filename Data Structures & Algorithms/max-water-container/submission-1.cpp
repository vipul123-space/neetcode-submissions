class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;

        int currMax = 0;
        while (i < j) {
            currMax = max(currMax,( (j - i) * min(heights[i], heights[j])));

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return currMax;
    }
};
