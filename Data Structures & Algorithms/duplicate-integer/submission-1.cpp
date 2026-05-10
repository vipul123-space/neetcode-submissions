class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    set<int> st;

    for(auto num:nums){
        st.insert(num);
    }

    if(st.size()!=nums.size()){
        return true;
    }
    return false;
    }
};
