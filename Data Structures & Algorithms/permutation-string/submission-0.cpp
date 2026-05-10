class Solution {
public:
    bool checkInclusion(string s1, string s2) {
            if (s1.size() > s2.size()) return false;

    map<char, int> m1;
    map<char, int> m2;

    for (int i = 0;i < s1.size();i++) {
        m1[s1[i]]++;
        m2[s2[i]]++;
    }

    if (m1 == m2) return true;

    int n1 = s1.size();
    int n2 = s2.size();

    for (int i = n1;i < n2;i++) {
        m2[s2[i]]++;
        m2[s2[i - n1]]--;

        if (m2[s2[i - n1]] == 0) {
            m2.erase(s2[i - n1]);
        }

        if (m1 == m2) {
            return true;
        }
    }

    return false;
    }
};
