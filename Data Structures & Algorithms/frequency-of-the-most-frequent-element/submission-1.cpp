class Solution {
   public:
    int binarySearch(vector<int>& nums, int k, int target) {
        int left = 0;
        int right = target;
        long long ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long currWinSum = accumulate(nums.begin() + mid, nums.begin() + target + 1, 0LL);

            long long ope = 1LL * nums[target] * (target - mid + 1) - currWinSum;

            if (ope > k) {
                left = mid + 1;
            } else {
                ans = (target - mid + 1);
                right = mid - 1;
            }
        }

        return ans;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, binarySearch(nums, k, i));
        }

        return res;
    }
};