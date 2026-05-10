class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
    int left = 0;
    int right = 0;
    int minWind = INT32_MAX;;
    int sum = 0;

    while (right < nums.size()) {
        sum = sum + nums[right];

        while (sum >= target)
        {
            minWind = min(minWind, right - left + 1);
            sum = sum - nums[left];
            left++;
        }

        right++;

    }

       return minWind == INT32_MAX ? 0 : minWind;
    }
};