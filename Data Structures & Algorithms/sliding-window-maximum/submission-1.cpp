class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      
   deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices out of the current window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller values from the back of deque
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // Add current index
        dq.push_back(i);

        // Add max to result when we have a full window
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
    }
};
