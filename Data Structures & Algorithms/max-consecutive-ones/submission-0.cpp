class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
            int maxOnes = 0;
    int temp = 0;
    for (int num : nums)
    {
        if (num == 1)
        {
            temp += num;
            maxOnes = max(maxOnes, temp);
            continue;
        }
        temp = 0;
    }

    return maxOnes;
    }
};