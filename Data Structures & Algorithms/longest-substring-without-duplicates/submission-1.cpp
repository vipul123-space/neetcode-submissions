class Solution {
public:
    int lengthOfLongestSubstring(string s) {
   int start = 0;
    int end = 0;
    int maxLen = 0;

    set<int> st;
    int winLen = 0;
    while (end < s.size()) {

        while (st.count(s[end])) {
            st.erase(s[start]);
            start++;
        }
        st.insert(s[end]);
        maxLen = max(maxLen, end - start + 1);
        end++;

    }
    return maxLen;
    }
};
