class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int start = 0;
        int end = k - 1;

        int res = nums[end] - nums[start];

        while (end < nums.size() - 1) {
            start++;
            end++;

            res = min(res, nums[end] - nums[start]);
        }

        return res;
    }
};