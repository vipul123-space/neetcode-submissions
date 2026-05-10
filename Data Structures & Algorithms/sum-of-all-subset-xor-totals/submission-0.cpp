class Solution
{
public:
    vector<int> ans;
    int subsetXORSum(vector<int> &nums)
    {
        vector<int> temp;
        helper(nums, 0, temp);
        int result = accumulate(ans.begin(), ans.end(), 0);
        return result;
    }

    void helper(vector<int> &nums, int idx, vector<int> &temp)
    {
        if (idx <= nums.size())
        {

            int xorVal = accumulate(temp.begin(), temp.end(), 0, [](int a, int b)
                                    { return a ^ b; });
            ans.push_back(xorVal);
        }

        for (int i = idx; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            helper(nums, i + 1, temp);
            temp.pop_back();
        }
    }
};