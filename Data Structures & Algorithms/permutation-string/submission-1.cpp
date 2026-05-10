class Solution {
public:
    bool checkInclusion(string s1, string s2) {
            if (s2.size() < s1.size())
    {
        return false;
    }

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for (auto ch : s1)
    {
        mp1[ch]++;
    }

    int left = 0;
    int right = 0;

    while (right < s1.size())
    {
        mp2[s2[right]]++;
        right++;
    }

    if (mp1 == mp2)
        return true;

    while (right < s2.size())
    {
        mp2[s2[left]]--;

        if (mp2[s2[left]] == 0)
            mp2.erase(s2[left]);

        left++;

        mp2[s2[right]]++;

        if (mp1 == mp2)
            return true;

        right++;
    }

    return false;
    }
};
