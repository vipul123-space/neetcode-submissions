class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
            int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canEat(piles, h, mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
    }
    bool canEat(vector<int> &piles, int h, int mid)
{
    int totalHrs = 0;

    for (int pile : piles)
    {
        totalHrs += (pile + mid - 1) / mid;
    }

    return totalHrs <= h;
}
};
