class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        if(nums.size()==0){
            return false;
        }

        set<int> st;

        for(int ele:nums)
           st.insert(ele);


        return nums.size()==st.size()?false:true;
    }
};