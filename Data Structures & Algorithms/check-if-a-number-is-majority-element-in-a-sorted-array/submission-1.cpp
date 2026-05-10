class Solution {
public:
int findIndex(vector<int> &nums, int target, bool first)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            if (first)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}
bool isMajorityElement(vector<int> &nums, int target)
{
    int n = nums.size();
    int firstIdx = findIndex(nums, target, true);
    int secondIdx = findIndex(nums, target, false);

    if(firstIdx==-1 || !secondIdx==-1) return false;
    
    return (secondIdx - firstIdx + 1) > (n / 2);
}
};
