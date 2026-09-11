class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int i=0;
        int idx=i;

        while(i<nums.size()){

            if((nums[i]&1)==0){
                swap(nums[idx],nums[i]);
                idx++;
            }
            i++;
        }

        return nums;
    }
};