class Solution {
public:
    vector<int> computeLPS(string pattern) {
        vector<int> lps(pattern.size(), 0);
        int m = pattern.size();
        int i = 1;
        int len = 0;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else
                    i++;
            }
        }

        return lps;
    }

    bool kmpSearch(string text, string pattern) {
        if ((pattern.size() > text.size()) || pattern.size() == 0) {
            return false;
        }

        int n = text.size();
        int m = pattern.size();

        auto lps = computeLPS(pattern);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == m) {
                return true;
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        set<string> st;

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (i == j) {
                    continue;
                }

                if (kmpSearch(words[j], words[i])) {
                    st.insert(words[i]);
                }
            }
        }

        vector<string> ans(st.begin(), st.end());

        return ans;
    }
};