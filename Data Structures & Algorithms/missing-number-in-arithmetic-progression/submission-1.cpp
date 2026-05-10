class Solution {
public:
    int missingNumber(vector<int>& arr) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    int difference = (arr[high] - arr[low]) / n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int expected = arr[0] + (mid * difference);

        if (arr[mid] == expected)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return arr[0] + (low * difference); 
    }
};
