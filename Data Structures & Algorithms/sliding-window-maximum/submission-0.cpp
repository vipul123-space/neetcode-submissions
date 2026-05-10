class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      
    int right = 0;
    int left = 0;
    int maximum = INT_MIN;
    vector<int> ans;
    while (right < k)
    {
        maximum = max(maximum, nums[right]);
        right++;
    }
    ans.push_back(maximum);

    while (right < nums.size())
    {
        left++;
        maximum = *max_element(nums.begin() + left, nums.begin() + left + k);
        ans.push_back(maximum);
        right++;
    }
    return ans;  
    }
};
