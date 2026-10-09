class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int start = 0;
        int ans = 0;
        int product = 1;
        for (int end = 0; end < nums.size(); end++) {
            product *= nums[end];

            while (start < nums.size() && product >= k) {
                product = product / nums[start];
                start++;
            }

            if (product < k) ans += (end - start + 1);
        }

        return ans;
    }
};