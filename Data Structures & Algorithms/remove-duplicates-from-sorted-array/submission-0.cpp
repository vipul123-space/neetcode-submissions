class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1) return 1;

        int k = 1; // Position for the next unique element
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};