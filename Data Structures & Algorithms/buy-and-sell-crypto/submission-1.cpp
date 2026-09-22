class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = INT_MAX;
        for (int price : prices) {
            int buy = min(price, buy);

            if (price >buy) {
                res = max(res, price - buy);
            }
        }

        return res;
    }
};
