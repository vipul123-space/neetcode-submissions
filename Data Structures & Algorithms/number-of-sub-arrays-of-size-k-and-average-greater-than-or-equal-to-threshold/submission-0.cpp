class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if (k > arr.size()) {
            return 0;
        }

        int start = 0;
        int sum = 0;
        int numSubArry = 0;
        for (int end = 0; end < arr.size(); end++) {
            sum += arr[end];

            if ((end - start + 1) == k) {
                if (sum / k >= threshold) {
                    numSubArry++;
                }

                sum -= arr[start];
                start++;
            }
        }

        return numSubArry;
    }
};