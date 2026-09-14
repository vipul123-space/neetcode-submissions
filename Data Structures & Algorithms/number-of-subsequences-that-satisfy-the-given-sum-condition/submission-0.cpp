class Solution {
   public:
    int numSubseq(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        const int MOD = 1000000007;
        sort(nums.begin(), nums.end());
        long long ans = 0;

        vector<int> power(nums.size());

        power[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            power[i] = (power[i - 1] * 2LL) % MOD;
        }

        while (i <= j) {
            int sum = nums[i] + nums[j];
            if (sum <= target) {
                ans = (ans + power[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};