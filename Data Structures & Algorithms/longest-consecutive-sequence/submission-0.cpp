class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        unordered_map<int, bool> s;
        for (auto num : nums)
        {
            s.insert({num, true});
        }

        for (auto num : nums)
        {
            if (s.find(num - 1) != s.end())
                s[num] = false;
        }

        int ans = 0;
        for (auto num : nums)
        {
            if (s[num] == true)
            {
                int tempLength = 1;
                while (s.find(num + tempLength) != s.end())
                {
                    tempLength++;
                }
                ans = max(ans, tempLength);
            }
        }

        return ans;
    }
};
