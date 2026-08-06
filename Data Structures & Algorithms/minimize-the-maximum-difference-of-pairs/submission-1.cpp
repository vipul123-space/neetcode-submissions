class Solution {
public:
bool isPossible(vector<int> &nums, int dist, int p)
{
    int pair = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if ((nums[i] - nums[i - 1]) <= dist)
        {
            pair++;
            i++;
        }
    }

    return pair >= p;
}

int minimizeMax(vector<int> &nums, int p)
{
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.back() - nums.front();

    int res = right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isPossible(nums, mid, p))
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return res;
}
};