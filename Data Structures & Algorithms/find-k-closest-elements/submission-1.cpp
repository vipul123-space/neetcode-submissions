class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> absoluteArr;
    for (auto ele : arr) {
        absoluteArr.push_back(abs(ele - x));
    }

    int left = 0;
    int right = 0;
    int sum = INT32_MAX;
    int currSum = 0;
    int minStartIdx = 0;   // this pointer will store the starting index of minimum sum window



    while (right < k) {
        currSum += absoluteArr[right];
        right++;
    }

    if (currSum < sum) {
        minStartIdx = right - k;
        sum = min(sum, currSum);
    }

    while (right < absoluteArr.size()) {

        currSum = currSum + absoluteArr[right] - absoluteArr[right - k];

        right++;
        if (currSum < sum) {
            minStartIdx = right - k;
            sum = min(sum, currSum);
        }


    }

    return vector<int>(arr.begin() + minStartIdx, arr.begin() + minStartIdx + k);
    }
};