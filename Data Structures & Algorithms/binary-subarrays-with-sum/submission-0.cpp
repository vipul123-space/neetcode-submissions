class Solution {
   public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int start = 0;
        int sum = 0;
        int ans = 0;

        for (int end = 0; end < nums.size(); end++) {

            sum += nums[end];

            while (sum > goal) {
                sum -= nums[start];
                start++;
            }

            ans += end - start + 1;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};