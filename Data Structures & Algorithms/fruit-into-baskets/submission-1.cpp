class Solution {
   public:
    int totalFruit(vector<int>& nums) {
        int countZeros = 0;
        int start = 0;
        int ans = 0;
        unordered_map<int, int> mp;

        for (int end = 0; end < nums.size(); end++) {

            mp[nums[end]]++;

            while (mp.size() > 2) {

                mp[nums[start]]--;
                if(mp[nums[start]]==0){

                mp.erase(nums[start]);
                }
                start++;
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};