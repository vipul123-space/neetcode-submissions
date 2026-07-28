class Solution {
   public:
    int mySqrt(int x) {
        long long low = 1;
        long long high = x;
        long long ans=0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sqr = mid * mid;
            if (x == sqr) {
                return mid;
            } else if (x > sqr) {
                low = mid + 1;
                ans=max(mid,ans);

            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};