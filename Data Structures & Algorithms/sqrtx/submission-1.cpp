class Solution {
public:
    int mySqrt(int num) {

        if(num==0 || num==1){
            return num;
        }

        long long left = 1, right = num / 2;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sqaure = mid * mid;

            if (sqaure == num) {
                return mid;
            } else if (sqaure < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};