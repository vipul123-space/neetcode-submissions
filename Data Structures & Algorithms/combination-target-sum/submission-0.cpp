class Solution {
public:
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
              vector<int> temp;
    helper(nums, target, temp, 0);
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
        helper(nums, target - nums[i], temp, i);
        temp.pop_back();
    }
}
};
