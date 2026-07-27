class Solution {
   public:
    int arrangeCoins(int n) {
        long long low = 1;
        long long high = n;
        long long res = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long target = (mid * (mid + 1)) / 2;

            if (target > n) {
                high = mid - 1;
            } else {
                low = mid + 1;
                res = max(res, mid);
            }
        }

        return (int)res;
    }
};