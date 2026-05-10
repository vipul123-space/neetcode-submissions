class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    int minRange = *max_element(weights.begin(), weights.end());
    int maxRange = accumulate(weights.begin(), weights.end(), 0);

    while (minRange <= maxRange)
    {
        int mid = minRange + (maxRange - minRange) / 2;
        if (canShip(weights, mid, days))
        {
            maxRange = mid - 1;
        }
        else
        {
            minRange = mid + 1;
        }
    }
    return minRange;
    }
    bool canShip(vector<int>& weights, int cap, int days) {
        int currLoad = 0;
        int currDay = 1;
        for (int weight : weights) {
            if (currLoad + weight > cap) {
                currDay = currDay + 1;
                currLoad = weight;
            } else {
                currLoad += weight;
            }
        }
        return currDay <= days;
    }
};