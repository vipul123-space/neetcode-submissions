class Solution {
public:
    int helper(vector<int>& nums, int target, bool first) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (first) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int first = helper(nums, target, true);
        int last = helper(nums, target, false);
        ans[0] = first;
        ans[1] = last;

        return ans;
    }
};