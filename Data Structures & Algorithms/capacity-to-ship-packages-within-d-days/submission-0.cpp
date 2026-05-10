class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
           int minRange = *max_element(weights.begin(), weights.end());
    int maxRange = accumulate(weights.begin(), weights.end(), 0);

    for (int cap = minRange; cap <= maxRange; cap++)
    {
        if (canShip(weights, cap, days))
        {
            return cap;
        }
    }
    return minRange; 
    }
            bool canShip(vector<int> &weights, int cap, int days)
        {
            int currLoad = 0;
            int currDay = 1;
            for (int weight : weights)
            {
                if (currLoad + weight > cap)
                {
                    currDay = currDay + 1;
                    currLoad = weight;
                }
                else
                {
                    currLoad += weight;
                }
            }
            return currDay <= days;
        }
};