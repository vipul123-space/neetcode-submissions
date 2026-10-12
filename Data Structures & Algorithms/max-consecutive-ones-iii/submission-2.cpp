class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int countZero = 0;
        int ans = 0;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0) {
                countZero++;
            }

            while (countZero > k) {
                if (nums[start] == 0) {
                    countZero--;
                }
                start++;
            }

            ans = max(ans, (end - start + 1));
        }

        return ans;
    }
};