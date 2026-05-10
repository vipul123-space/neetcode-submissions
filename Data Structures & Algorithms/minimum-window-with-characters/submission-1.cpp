class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    for (auto ch : t) {
        mp[ch]++;
    }

    int right = 0;
    int left = 0;
    int minimumWindow = INT32_MAX;
    int count = 0;
    int t_size = t.size();
    int idx = -1;

    while (right < s.size())
    {
        if (mp[s[right]] > 0) {
            count++;
        }
        mp[s[right]]--;

        while (t_size == count)
        {
            if ((right - left + 1) < minimumWindow) {
                minimumWindow = right - left + 1;
                idx = left;
            }

            mp[s[left]]++;
            if (mp[s[left]] > 0) {
                count--;
            }

            left++;
        }

        right++;
    }
    return idx < 0 ? "" : s.substr(idx, minimumWindow);
    }
};
