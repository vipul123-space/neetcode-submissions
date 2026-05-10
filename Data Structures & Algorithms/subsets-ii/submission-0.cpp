class Solution {
public:
 vector<vector<int>> ans;

void helper(vector<int> &nums, vector<int> &temp, int idx)
{
    if (temp.size() <= nums.size())
    {
        ans.push_back(temp);
    }

    if (temp.size() > nums.size())
    {
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        helper(nums, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> temp;
    helper(nums, temp, 0);
    set<vector<int>> st;
    for (auto &arr : ans)
    {
        sort(arr.begin(), arr.end());
        st.insert(arr);
    }
    ans.clear();
    ans.assign(st.begin(), st.end());
    return ans;
}
};
