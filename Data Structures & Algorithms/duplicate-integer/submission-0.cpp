class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto ele:nums){
            st.insert(ele);
        }

        if(st.size()!=nums.size()){
            return true;
        }

        return false;
    }
};
