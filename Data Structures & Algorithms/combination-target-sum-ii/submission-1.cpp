class Solution {
public:
        vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
      vector<int> temp;
    sort(nums.begin(), nums.end());
    helper(nums, target, temp, 0);
    set<vector<int>> st(ans.begin(), ans.end());
    ans.clear();
    ans.assign(st.begin(), st.end());

    return ans;
        }
        vector<vector<int>> ans;

void helper(vector<int> &nums, int target, vector<int> &temp, int idx)
{
  if (target == 0)
    {
        ans.push_back(temp);
    }

    if (target < 0)
    {
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        helper(nums, target - nums[i], temp, i+1);
        temp.pop_back();
    }
}
};
