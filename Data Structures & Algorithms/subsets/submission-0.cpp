class Solution {
public:
vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> temp; 
        subset(nums,0,temp);

        return ans;
    }

    void subset(vector<int> &nums, int idx, vector<int> &temp)
{
    if (idx <= nums.size())
        ans.push_back(temp);

    for (int i = idx; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        subset(nums, i + 1, temp);
        temp.pop_back();
    }
}
};
