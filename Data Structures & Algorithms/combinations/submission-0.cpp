class Solution {
public:
   vector<vector<int>> ans;

void helper(vector<int> &temp, int idx, int n, int k)
{
    if (temp.size() == k)
    {
        ans.push_back(temp);
    }
    if (temp.size() > k)
    {
        return;
    }

    for (int i = idx; i <= n; i++)
    {
        temp.push_back(i);
        helper(temp, i + 1, n, k);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<int> temp;
    helper(temp, 1, n, k);
    return ans;
}
};