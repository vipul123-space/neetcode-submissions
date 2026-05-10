class Solution {
public:
vector<vector<int>> ans;
  void helper(vector<int> &nums, vector<int> &temp, vector<bool> &used)
{
    if (temp.size() == nums.size())
    {
        ans.push_back(temp);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!used[i])
        {

            temp.push_back(nums[i]);
            used[i] = true;
            helper(nums, temp, used);
            temp.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> temp;
    vector<bool> used(nums.size(), false);
    helper(nums, temp, used);
    return ans;
}
};
